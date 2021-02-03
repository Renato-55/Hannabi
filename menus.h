#ifndef _MENUSH_	//protectes from multiple including...
#define _MENUSH_	//... needs an #endif at bottom
#include "TableAndMore.h"


void barra_de_historico ()
{
	int i=0;
	gotoxy(90,5);printf("Hístorico ");
	setForeColor(11);
	gotoxy(92,7);printf("Pistas : ");
	gotoxy(92,13);printf("Descarte : ");
	gotoxy(92,19);printf("Jogadas : ");
	setForeColor(15);
	for (i=0;i<25;i++)
	{
		setForeColor(11);
		gotoxy(87,5+i);printf("%c",124);
		setForeColor(15);
	}
	
}
void imposivel_retomar ()
{
	system("cls");
			printf("\n\n\t\tNão iniciou um jogo\n\t\tImpossivél retomar");
			delay(1);
}
void escolha_opcao (int *OPCAO,int min, int max,int x,int y)
{
	int aux;	
	do
	{										 // Escreve o menu ( HANNABI E AS OPCOES )
	scanf("%d", &aux);
	if (aux<min || aux>max)
	{
	mensagem_de_erro(x,y);
	}										// Indepente do valor de OPCAO o ecra limpa para a proxima operacao
	}while(aux<min || aux>max);
	
	*OPCAO = aux;
}
void menu_principal_hannabi(int *OPCAO,int min, int max,int x,int y)
{
	printMENU();
	escolha_opcao(OPCAO,1,4,39,15);
	system("cls");

}	
void resetarVariaveis (int *vidas,int *pistas,int *pontuacao,int *possivel_ir_para_recomecar_jogo,int *red,int *white,int *blue,int *yellow,int *green,int *contador_discarte, carta descarte[],int *aux_contador_pistas,int *aux_contador_descarte,int *aux_contador_jogadas)
{
	int i;
		*vidas=3;
		*pistas=8;
		*pontuacao=0; 					// 	Sempre que é para comecar o jogo as vidas, pistas e pontuacao sao colocadas ao valor original
		*possivel_ir_para_recomecar_jogo=1;				//  permite que o jogo seja retomado
		*red=0;
		*white=0;
		*blue=0;
		*yellow=0;
		*green=0;
		*contador_discarte=0;
		*aux_contador_pistas = -1;
		*aux_contador_descarte = -1;
		*aux_contador_jogadas = -1;
		for(i=0;i<50;i++)
		{
	 	descarte[i].num = 0;
	 	descarte[i].cor = 0;
		}
	
}
void criar_e_apresentar_deck (carta deck[], carta J1[],carta J2[],int turno,char nome[],int red,int white,int blue,int yellow,int green)
{
	criarDECK(deck); 							// 	cria o baralho	
	baralhar(deck);								//	distribui posicoes aleatorias e sempre diferentes para cada carta	
	Player1(J1,deck,nome,turno);					// 	deck do PLAYER 1, constituido por 5 cartas
	Player2(J2,deck);						// 	deck do PLAYER 2, constituido por 5 cartas
	CaraCoroa(nome,turno);       					// 	decide que jogador vai jogar	
	grelha_discarte();								// 	lugar reservado para as cartas de destaque ( no inicio tudo é igual a 0 ) 
	escrever_pilha_na_mesa (green,red,blue,yellow,white);
	barra_de_historico ();
}
void resetarPosicoes (int *op , int *op_1 , int *pos )
{

	*op=0;*op_1=0;*pos=0;								// reseta os valores para que seja possivel o historico   
} 			
void show_mesa (int pistas, int vidas, int pontuacao, int *op, carta deck[],/* */int red,int green,int blue,int yellow,int white,carta descarte[],int turno)
{

	
		mostrarVIDAS(pistas,vidas);						//	vai mostrar as vidas e as pistas no canto superior direito
		mostrarDECK_1_POS(deck);						//	serve para saber o numero de cartas que ainda estao disponiveis no baralho
		cartasParaA_Mesa();								// 	molde onde vao ficar as cartas de cada cor ordenadas por sequencia
		print_pontuacao(pontuacao);						// 	exibe a pontuacao no ecra
		

		
		atualizar_VIDAS(pistas,vidas);
		escrever_pilha_na_mesa(green,blue,red,white,yellow);
		printOPCOES();
		if(turno == 0)
		{
		escolha_opcao( op , 1 , 4 , 37 , 31 );
	    }
		clearOPCOES(); 
	    
}
void erro_pistas  (int *op_1)
{
			DarPista_OP();	
			escolha_opcao(op_1,1,3,37,31);
			clearOPCOES();
}
void erro_posicao (int *pos)
{
				printMENU_pos();
				escolha_opcao(pos,0,5,37,31);
				
}
void descartar_uma_carta (int opcao,int pos,carta J1[],carta J2[],carta deck[],carta descarte[], int turno,int *pistas,int vidas,int *aux_contador_descarte,int *aux_contador_jogadas,char username[])
{
	int aux_pistas=*pistas;
	
			if(pos >=1 && pos <= 5 )
			{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_pistas=aux_pistas+1;
			atualizar_VIDAS(aux_pistas,vidas);
			}
			
	*pistas=aux_pistas;
}
void historico_pistas (carta J1[],carta J2[],int pos, char nome[], int *aux_contador_pistas,int turno,int OPCAO_1_Pistas)
{
	char * cores[]= {"verde","azul","vermelho","branco","amarelo"};																						
	int aux_contador=*aux_contador_pistas;	
	char * aux_cor_1[5], * aux_cor_2[5];
	int i=0;
	pos--;
	
	if(aux_contador == 3 || aux_contador<0 )aux_contador=0;
	
	
	if(J1[pos].cor == 2  ) aux_cor_1[aux_contador] = cores[0];   		// passar o numero da cor a texto
	if(J1[pos].cor == 3  ) aux_cor_1[aux_contador] = cores[1];    	
	if(J1[pos].cor == 4  ) aux_cor_1[aux_contador] = cores[2];	
	if(J1[pos].cor == 15 ) aux_cor_1[aux_contador] = cores[3];
	if(J1[pos].cor == 14 ) aux_cor_1[aux_contador] = cores[4];			
	
	if(J2[pos].cor == 2  ) aux_cor_2[aux_contador] = cores[0];   		// passar o numero da cor a texto
	if(J2[pos].cor == 3  ) aux_cor_2[aux_contador] = cores[1];    	
	if(J2[pos].cor == 4  ) aux_cor_2[aux_contador] = cores[2];	
	if(J2[pos].cor == 15 ) aux_cor_2[aux_contador] = cores[3];
	if(J2[pos].cor == 14 ) aux_cor_2[aux_contador] = cores[4];
	
	for(i=0;i<3;i++)
	{
		gotoxy(91,9+i);printf("  ");
	}
	gotoxy(93,9 + aux_contador);printf("                                                                            ");
	setForeColor(6);
	gotoxy(91,9 + aux_contador);printf("->");
	setForeColor(15);
	
	if (turno == 1)
	{
		if( OPCAO_1_Pistas == 1)	
		{
			gotoxy(93,9+aux_contador);printf("Pista para o ");
			setForeColor(11);
			printf("%s ", "BOT");
			setForeColor(15);
			printf("sobre o número da %dª carta = %d ", pos+1 , J2[pos].num);	
			aux_contador=aux_contador+1;
		}
		if(OPCAO_1_Pistas == 2 )
		{
			gotoxy(93,9+aux_contador);printf("Pista para o");
			setForeColor(11);
			printf(" %s","BOT");
			setForeColor(15);
			printf(" sobre a cor da %dª carta =",pos+1);
			setForeColor(J2[pos].cor);
			printf(" %s ", aux_cor_2[aux_contador]);		
			setForeColor(15);
			aux_contador = aux_contador+1;
		}
	}
	
	if(turno == 0)
	{
		if( OPCAO_1_Pistas == 1)
		{
			gotoxy(93,9+aux_contador);printf("Pista para o ");
			setForeColor(11);
			printf("%s ", nome);
			setForeColor(15);
			printf("sobre o número da %dª carta = %d ", pos+1 , J1[pos].num);
			aux_contador=aux_contador+1;
		}
		if(OPCAO_1_Pistas == 2 )
		{
			gotoxy(93,9+aux_contador);printf("Pista para o");
			setForeColor(11);
			printf(" %s",nome);
			setForeColor(15);
			printf(" sobre a cor da %dª carta =",pos+1);
			setForeColor(J1[pos].cor);
			printf(" %s ", aux_cor_1[aux_contador]);		
			setForeColor(15);
			aux_contador=aux_contador+1;
		}
	}
	
	
	
	*aux_contador_pistas=aux_contador;
}
void apoio_setas_historico (int aux_contador_pistas, int aux_contador_descarte, int aux_contador_jogadas )
{
	int i;
	
	setForeColor(11);
	
	if( aux_contador_pistas   == -1)
	{
	}
	else
	{
		gotoxy(91,8+aux_contador_pistas);    printf("->");
	}
	
	
	if( aux_contador_descarte   == -1)
	{
	}
	else
	{
		gotoxy(91,14+ aux_contador_descarte);    printf("->");
	}	
	
	
	if( aux_contador_jogadas   == -1)
	{
	}
	else
	{
		gotoxy(91,20 + aux_contador_jogadas );    printf("->");
	}
	
	setForeColor(15);
}


























#endif
