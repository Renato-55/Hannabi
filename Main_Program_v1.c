#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#include "global.h"
#include "Header.h"
#include "deck.h"
#include "TableAndMore.h"
#include "menus.h"
#include "BOT_CODE.h"
//  DEFINE

// FUNCOES 

    /////////////////
   //			  //
  // MAIN PROGAM //
 //			    //
/////////////////


void main () {
	srand(time(NULL));
	setlocale(LC_ALL,"");
	
	FullScreen();	
	int carta_jogada=0;	// historico						
	int OPCAO=0,op=0,op_1=0;							// Usada no menu para o jogador decidir o caminho que pretende seguir
	int pos; 											// posicao das cartas do jogador 
	int vidas=3,pistas=8; 								// numero inicial de vidas e pistas
	char nome[16];										// nome do Jogador
	int pontuacao=0;									// pontuacao
    int aux_contador_pistas=0,aux_contador_descarte=0,aux_contador_jogadas=0; // ajudam no historico				
	int red=0,white=0,blue=0,yellow=0,green=0;			// valor das pilhas onde se jogam as cartas
	int contador_discarte=0;							// numero de cartas descartadas
	int possivel_ir_para_recomecar_jogo=0,BOT_jogou=0;	// verifica se o jogo ja foi exucutado ou nao || decide se o bot ja jogou
	carta J1[5];										// J1 J2 e my_deck pertencem à struct carta
	carta J2[5];
	carta my_deck[50];									// deck principal
	carta descarte[50]; 								//descarte descarte
	int	turno = rand () % 2 ;								// define o jogador que vai jogar 		 ||  	1 BOT  --- 0 JOGADOR

	
////	char not_lixo[50]= "" ;
////	char lixo = {'\n'} ;
////	
////	FILE *fp = NULL;
////	
////	fopen_s (&fp,"texte.txt","r");
////	
////	if(fp== NULL)printf("\n\n\t\tERRO DO FICHEIRO");
////	
////	fscanf_s(fp,"%c",&lixo,1);  fscanf_s(fp,"%s",not_lixo,sizeof(not_lixo)); 
////	
////	
////	fclose(fp);
////	
////	printf("%s",not_lixo);
////	system("pause");
	
	pedirNOME(nome);									// Funcao para pedir o nome do jogador ( ate 16 carateres ) 
	
//	label menu;
	menu: 												// ONDE ESTA O MENU DO HANNABI 
	{
		menu_principal_hannabi(&OPCAO,1,4,39,15);
	}			
	
	switch(OPCAO)    									// 	OPÇÃO 1 : CRIA UM JOGO  | OPÇÃO 2 : RETOMA O JOGO | OPÇÃO 3 : INTRUCÕES | OPÇÃO 4 : SAIR DO PROGAMA 
	{    
		// OPÇÃO 1 
		case 1:{
		resetarVariaveis ( &vidas , &pistas , &pontuacao , &possivel_ir_para_recomecar_jogo , &red , &white , &blue , &yellow , &green , &contador_discarte , descarte ,&aux_contador_pistas,&aux_contador_descarte,&aux_contador_jogadas);
		criar_e_apresentar_deck ( my_deck, J1, J2,  turno, nome, red , white , blue , yellow , green); // apresenta o deck ,pilhas ...
		
		// Label menu_1;								 // menu das opcoes principais !!!
		menu_1:
		{
			
		
			
		if(vidas == 0 ) 							// no caso da pessoa perder todas as vidas o jogo vai encerrar e voltar ao menu
		{delay(2);print_gameover();
		goto menu;
		}
		if(pontuacao==25) 							// no caso de a pontuacao chegar ao maximo (25) a pessoa vai automaticamente ganhar o jogo 
		{delay(2);print_youwon();
		goto menu;}	
		
		show_mesa(pistas, vidas, pontuacao, &op, my_deck,red, green, blue, yellow, yellow,descarte, turno);	// imprime tudo o que diz respeito á mesa

		}
		
		
		if(turno ==  1)
		{
			BOT_jogou = 0 ;
			printOPCOES();
			delay(1);
			apoio_setas_historico (aux_contador_pistas, aux_contador_descarte, aux_contador_jogadas );	
			
			primeira_condicao_BOT ( J1 , &turno , &pistas , vidas , nome , pontuacao, &aux_contador_pistas , descarte, &BOT_jogou );
			segunda_condicao_BOT ( J2 ,  &green , &red , &blue , &yellow , &white, nome ,  &aux_contador_jogadas, my_deck, &pontuacao , &BOT_jogou );
			terceira_condicao_BOT (  J1 , J2 ,  turno , &aux_contador_pistas ,  nome ,  green ,  red ,  blue ,  yellow ,  white , &pistas , vidas , &BOT_jogou);
			quarta_condicao_BOT ( J1 , J2 ,descarte , &aux_contador_descarte , &BOT_jogou, &pistas,vidas,&aux_contador_jogadas,my_deck, green ,  red ,  blue ,  yellow ,  white );
		
				
			swap_player(&turno);
			print_WhosNext(turno,nome);
			goto menu_1;
		}
		
		
		
			
			switch(op)   								 // OPÇÃO 1 : PISTA | OPÇÃO 2 : DESCARTE | OPÇÃO 3 : JOGAR | OPÇÃO 4 : SAIR DO PROGAMA 
			{ 
			// OPÇÃO 1 	PISTA
			case 1 :{
			verificar_Pistas(pistas);
			if(pistas == 0) goto menu_1;
			erro_pistas  (&op_1);            			// ve se o utilizador errou na escolha
			if (op_1 == 1 || op_1 == 2)					// OPÇÃO 1 : NUMERO | OPÇÃO 2 : COR | OPÇÃO 3 : VOLTAR
				{
				erro_posicao(&pos);
				if(pos==0)goto menu_1;
				if(pos >=1 && pos <= 5 )
				{																  // este switch muda os turnos 
				swap_player(&turno);
		/*	trocar_de_jogador(turno,J1,J2,nome);*/print_WhosNext(turno,nome);
			
				apoio_setas_historico (aux_contador_pistas, aux_contador_descarte, aux_contador_jogadas );
				historico_pistas (J1, J2, pos,  nome,  &aux_contador_pistas, turno, op_1);
				
				evidenciar_PISTA(J1,J2,op_1,&pos,turno,nome,&pistas);					// vai evidenciar a pista que o jogador vai dar 
				atualizar_VIDAS(pistas,vidas);			 						// Apesar da funcao de chamar atualizar vidas, ela atualiza ambas, quer as pistas, quer as vidas
				goto menu_1;
				}
				}
				if (op_1==3)goto menu_1;														 // VOLTAR "OPCAO 3"	
				}
					
			// OPÇÃO 2  DESCARTE
			case 2 :{
			verificar_descarte(pistas);
			if(pistas == 8)goto menu_1;
			
			erro_posicao(&pos);
			if(pos==0)goto menu_1;
			apoio_setas_historico (aux_contador_pistas, aux_contador_descarte, aux_contador_jogadas );
			descartar_uma_carta (op, pos, J1, J2, my_deck, descarte,  turno, &pistas, vidas,&aux_contador_descarte,&aux_contador_jogadas,nome);
							
			swap_player (&turno);
	/*      trocar_de_jogador(turno,J1,J2,nome);*/print_WhosNext(turno,nome);
			goto menu_1;
			break;
		}

			// OPÇÃO 3 JOGAR
			case 3 :{
			erro_posicao(&pos);
			if(pos == 0)goto menu_1;
			apoio_setas_historico (aux_contador_pistas, aux_contador_descarte, aux_contador_jogadas );
			verificar_cor ( op,J1, J2, my_deck, descarte, pos, &red, &blue, &yellow, &green, &white, &vidas, pistas, &pontuacao, carta_jogada, turno ,nome,&aux_contador_descarte,&aux_contador_jogadas);																	
			swap_player(&turno);
	/*	    trocar_de_jogador(turno,J1,J2,nome);*/print_WhosNext(turno,nome);
			goto menu_1;
			break;
		}
		
			// OPÇÃO 4 SAIR DO PROGAMA 
			case 4 :{
			goto menu;
			break;
			}
			}
		}
	
	
		// OPÇÃO 2
		case 2:{
		if(possivel_ir_para_recomecar_jogo == 1)				// no caso do jogo já ter iniciado ele retomado
		{
		print_Player1_All_Cards(J1,turno,nome);
		print_Player2_Cards(J2);	
		escrever_descarte_opcao_2(descarte);
		barra_de_historico ();
		goto menu_1;
		}	
		
		if(possivel_ir_para_recomecar_jogo == 0)			 	// o jogo nao comecou logo nao pode ser retomado
		{
			imposivel_retomar ();
			goto menu;
		}
		break;
		}
		
		// OPÇÃO 3
		case 3:{
		printRULES();									// Escreve AS REGRAS DO JOGO
		goto menu;
		break;
		}
		
		// OPÇÃO 4
	    case 4:{
		break;
	    }
		}
		
}




