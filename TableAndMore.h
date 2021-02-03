#ifndef _TABLEANDMORE_		//protectes from multiple including...
#define _TABLEANDMORE_		//... needs an #endif at bottom

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "deck.h"


void print_gameover() 														// print game over 
{
	system("cls");
	gotoxy(5, 6);printf("    _______   _______   __   __   _______    _______   __   __   _______   _______     ");
	gotoxy(5, 7);printf("   |       | |   _   | |  |_|  | |       |  |       | |  | |  | |       | |    _  |    ");
	gotoxy(5, 8);printf("   |    ___| |  |_|  | |       | |    ___|  |   _   | |  |_|  | |    ___| |   | | |    ");
	gotoxy(5, 9);printf("   |   | __  |       | |       | |   |___   |  | |  | |       | |   |___  |   |_| |_ ");
	gotoxy(5,10);printf("   |   ||  | |       | |       | |    ___|  |  |_|  | |       | |    ___| |    __  |  ");
	gotoxy(5,11);printf("   |   |_| | |   _   | | ||_|| | |   |___   |       |  |     |  |   |___  |   |  | |  ");
	gotoxy(5,12);printf("  	|_______| |__| |__| |_|   |_| |_______|  |_______|   |___|   |_______| |___|  |_|  ");
	delay(1);
}
void print_youwon ()														// printf you won
{
	system("cls");
	gotoxy(5, 6);printf("   __   __  _______  __   __      _     _  _______  __    _    ");
	gotoxy(5, 7);printf("  |  | |  ||       ||  | |  |    | || || ||       ||   | | |  ");
	gotoxy(5, 8);printf("  |  |_|  ||   _   ||  | |  |    | || || ||   _   ||   |_| |   ");
	gotoxy(5, 9);printf("  |       ||  | |  ||  |_|  |    |       ||  | |  ||       |  ");
	gotoxy(5,10);printf("  |_     _||  |_|  ||       |    |       ||  |_|  ||  _    |  ");
	gotoxy(5,11);printf("    |   |  |       ||       |    |   _   ||       || | |   |   ");
	gotoxy(5,12);printf("    |___|  |_______||_______|    |__| |__||_______||_|  |__|   ");
	delay(1);	
}
void printMENU ()															// print menu
{
	system("cls");
		printf("                               _   _     ___     _   _    _   _     ___    ______   _____ ");
	    printf("\n");
    printf("                              | | | |   / _ \\   | \\ | |  | \\ | |   / _ \\   | ___ \\ |_   _|");
        printf("\n");
	printf("                              | |_| |  / /_\\ \\  |  \\| |  |  \\| |  / /_\\ \\  | |_/ /   | |  ");
	    printf("\n");
    printf("                              |  _  |  |  _  |  | . ` |  | . ` |  |  _  |  | ___ \\   | |   ");
        printf("\n");
	printf("                              | | | |  | | | |  | |\\  |  | |\\  |  | | | |  | |_/ /  _| |_  ");
    printf("\n");
    printf("                              \\_| |_/  \\_| |_/  \\_| \\_/  \\_| \\_/  \\_| |_/  \\____/   \\___/  ");
        printf("\n");
                printf("\n");
                        printf("\n");
                                printf("\n");
                                        printf("\n");
	printf("                                                 1 - Iniciar o jogo;\n");
	printf("                                                 2 - Retomar o jogo;\n");
	printf("                                                  3 - Instruções;\n");
	printf("                                                     4 - Sair.\n");
	    printf("                                                          ");
	            printf("\n");
                printf("\n");
                        printf("\n");
                                printf("\n");
                                        printf("\n");
                                        	                                        printf("Trabalho realizado por: ");
                                        	                                        printf("\n");
                                     	printf("Al70569 - Diogo Barbosa;");
                                        printf("\n");
	                                    printf("Al70565 - Renato Barbosa;");
	                                    printf("\n");
                                        printf("Al70577 - Tomás Antunes.");
                                        printf("\n");
	gotoxy(42,15);printf("\t");
}
void printRULES ()															 // print rules
{
		system("cls");
		printf(" Hannabi é um jogo de cartas simples, em que o objetivo é fazer a maior pontuação possível.\n");
		printf(" Os conceitos básicos do jogo são cor e número. Haverá um monte de cartas para cada uma das\n");
	    printf(" cincos cores com os números 1, 2, 3, 4 e 5, jogados por esta ordem, estando o 5 no topo.\n");
	    printf(" Baralham-se todas as 50 cartas e distribuem-se 5 a cada jogador. \n Os jogadores devem segurar as suas cartas com as costas viradas para si de forma a não verem as suas próprias cartas. \n Desta forma não sabem quais são as suas cartas, mas, em contrapartida, sabem quais as cartas que os restantes jogadores têm.\n Ao alcance dos jogadores colocam-se as 8 fichas de pistas, que podem ser utilizadas pelos dois jogadores para ajudarem-se um ao outro.\n De igual modo existem 3 fichas de vida, se elas se esgotarem, o jogo acaba.\n O desafio é trocarem informações (pistas) para conseguirem jogar as cartas por ordem e, em conjunto, atingirem a maior pontuação possível.");
	    printf("\n\n\n ");
	    system("pause");
		system("cls");
}
void pedirNOME (char username[])											// Pedir nome ao jogador
{
	int tamanhodonome=0;
	
	do
	{
	printf("Digite o seu nome: ");
	gets(username);
	tamanhodonome=strlen(username);
	if (tamanhodonome>16)
	{
	printf("\nDemasiados caracteres\nTente novamente");
	delay(1);
	}
	system("cls");
	}while(tamanhodonome>16);
}
void mostrarVIDAS (int P,int V) 											// 		vai mostrar as pistas e as vidas no ecra
{
	
	int i=0;
	
	gotoxy(37,5);printf("Pistas: ");										// imprime as pistas
	for (i=0;i<P;i++)
	{
	setForeColor(5);
	showRectAt(45+i*3,5,2,2);
	gotoxy(46+i*3,6);
	printf("%c",17);
	resetColor();	
	}
	
	gotoxy(70,5);printf("Vidas: ");											// imprime as vidas
	for (i=0;i<V;i++)
	{
	setForeColor(4);
	showRectAt(77+i*3,5,2,2);
	gotoxy(78+i*3,6);
	printf("%c",'V');
	resetColor();	
	}

}
void limpar_VIDAS () 														// pinta todos os retangulos de preto ,uma vez que o fundo é preto funciona como uma " borracha "
{
	int i=0;
	
	for (i=0;i<8;i++) 														// pinta de cinzento / limpa as pistas
	{
	setForeColor(8);
	showRectAt(45+i*3,5,2,2);
	gotoxy(46+i*3,6);
	printf("%c",17);
	resetColor();	
	}
	
	for (i=0;i<3;i++)														// pinta de cinzento / limpa as vidas
	{	
	setForeColor(0);
	showRectAt(77+i*3,5,2,2);
	gotoxy(78+i*3,6);
	printf("%c",'V');
	resetColor();	
	}
}
void grelha_discarte()														// lugar reservado para as cartas de destaque ( no inicio tudo é igual a 0 )
{
	int j=0,i=0;
	
	setForeColor(2);gotoxy(59-6,15);	printf("VERDE");					// CORES
	setForeColor(3);gotoxy(59-5,16);	printf("AZUL");
	setForeColor(4);gotoxy(59-9,17);	printf("VERMELHO");
	setForeColor(15);gotoxy(59-7,18);	printf("BRANCO");
	setForeColor(14);gotoxy(59-8,19);	printf("AMARELO");
	resetColor();
	
	gotoxy(60,13);	printf("1");											// NUMEROS
	gotoxy(61,13);	printf("2");
	gotoxy(62,13);	printf("3");
	gotoxy(63,13);	printf("4");
	gotoxy(64,13);	printf("5");
	
		
	for (j=0;j<5;j++)														// coloca zeros em todas as posicoes da grelha
	{
		for(i=0;i<5;i++)
		{
			gotoxy(60+i,15+j);
			printf("0");
		}
	}
	
}
void printOPCOES () 														// imprime as opcoes de jogo
{	
	setForeColor(11);														
	showRectAt( 35, 24 , 17,  5);
	gotoxy(37,25);	printf("          - 1  ");								
	gotoxy(37,26);	printf("          - 2  ");
	gotoxy(37,27);	printf("          - 3  ");
	gotoxy(37,28);	printf("          - 4  ");

	setForeColor(15);
	gotoxy(37,25);	printf("Dar Pista");								
	gotoxy(37,26);	printf("Descartar");
	gotoxy(37,27);	printf("Jogar    ");
	gotoxy(37,28);	printf("SAIR     ");
	
	gotoxy(37,30);  printf("       ");										// limpa enventuais numeros pre existentes
	gotoxy(37,30);															// move o cursos para a posicao ( 37 , 30 )
}
void clearOPCOES () 														// limpa o quadro das opcoes
{
	gotoxy(37,25);	printf("              ");
	gotoxy(37,26);	printf("              ");			
	gotoxy(37,27);	printf("              ");
	gotoxy(37,28);	printf("              ");					
}
void DarPista_OP () 														// Menu das pistas
{
	setForeColor(11);
	gotoxy(37,25);	printf("             1");								
	gotoxy(37,26);	printf("             2");
	gotoxy(37,27);	printf("              ");
	gotoxy(37,28);	printf("             3");
	
	setForeColor(15);
	gotoxy(37,25);	printf("    Número ");								
	gotoxy(37,26);	printf("     Cor   ");
	gotoxy(37,27);	printf("           ");
	gotoxy(37,28);	printf("    Voltar ");
	gotoxy(37,30);  printf("       ");										// limpa enventuais numeros pre existentes
	gotoxy(37,30);															// move o cursos para a posicao ( 37 , 30 )
}
void verificar_Pistas (int p) 												// verifica se é possivel dar pistas 
{
	if(p==0)
	{
	gotoxy(37,31);printf("Não é possivel dar uma pista");					// imprime mensagem de erro
	delay(1);
	gotoxy(37,31);printf("                            ");
	}
	
}
void printMENU_pos () 														// perguntar Posicao
{
	
	
	setForeColor(15);
	gotoxy(37,25);	printf("   Posição    ");								// pede uma posicao a utilizador
	gotoxy(37,26);	printf("     da       ");
	gotoxy(37,27);	printf("    Carta     ");
	gotoxy(37,28);	printf("    - Voltar  ");
	
	setForeColor(11);
	gotoxy(37,28);	printf("  0");
	
	setForeColor(15);
	gotoxy(37,30);  printf("       ");										// limpa enventuais numeros pre existentes
	gotoxy(37,30);															// move o cursos para a posicao ( 37 , 30 )
}
void atualizar_VIDAS (int p,int v)											// 2 funcoes juntas, limpar vidas e mostrar VIDAS
{
	limpar_VIDAS();															
	mostrarVIDAS(p,v);
}
void evidenciar_PISTA (carta J1[], carta J2[],int op,int *pos,int turn,char username[],int *pista)	// evidencia a pista
{
	int i=0;
	int numero;
	int cor;
	int aux;
	int aux_pos=*pos;
	
	aux_pos=aux_pos-1;
	
	aux = *pista;
	aux = aux-1;
	*pista = aux;
	
	if( turn == 0 )
	{	
		if(op== 1)															// JOGADOR 1
		{
			for(i=0;i<5;i++)
			{													// PISTA SOBRE NUMEROS	
				if (J1[i].num == J1[aux_pos].num)
				{
				J1[i].jogavel_num = 1; 	
				numero=J1[i].num;
				showNumAt(i*5+7,7,numero);
				}
			}
		}
	else																			// PISTA SOBRE CORES
	{
			for(i=0;i<5;i++)
			{
			if (J1[i].cor == J1[aux_pos].cor)
			{
			J1[i].jogavel_cor = 1; 	
			cor=J1[i].cor;
			setForeColor(cor);
			showRectAt(5+i*5,5,4,4);
			resetColor();
			}
		}
	}
	}	
	else 																	// JOGADOR 2 
	{
		if(op== 1)	
		{
			for(i=0;i<5;i++)
			{													// PISTA SOBRE NUMEROS	
				if (J2[i].num == J2[aux_pos].num)
				{
				J2[i].jogavel_num = 1; 	
				numero = J2[i].num;
				showNumAt(i*5+7,27,numero);
				}
			}
		}
		else																		// PISTA SOBRE CORES	
		{
			for(i=0;i<5;i++)
			{
				if (J2[i].cor == J2[aux_pos].cor)
				{
				J2[i].jogavel_cor = 1; 	
				cor=J2[i].cor;
				setForeColor(cor);
				showRectAt(5+i*5,25,4,4);
				resetColor();
				}
			}
		}	
	}
	
	*pos=aux_pos;
}
void verificar_descarte (int p) 											// verifica se é possivel dar pistas 
{
	
	if(p==8)
	{
	gotoxy(37,31);printf("Não é possivel descartar uma carta");				// Imprime mensagem de erro
	delay(1);
	gotoxy(37,31);printf("                                  ");
	}
}
void limparCarta(int x) 													// pinta a carta de cinzento
{
		setForeColor(8);													
		showRectAt(5+x*5,5,4,4);
		gotoxy(7+x*5,7);
		printf("%c",169);
		resetColor();
}
void historico_descarte (int OPCAO,carta descarte[],int *aux_contador_descarte,int *aux_contador_jogadas,int contador_descarte,int turno,int pos,char username[]) // historico descarte
{
	int aux_contador = *aux_contador_descarte;
	int aux_contador_1 = *aux_contador_jogadas;
	char* cores[]= {"verde","azul","vermelho","branco","amarelo"};
	char* aux_cor[5];
	int i=0;
	
	if(aux_contador   == 3  || aux_contador   < 0  )       aux_contador   = 0;
	if(aux_contador_1 == 3  || aux_contador_1 < 0  )       aux_contador_1 = 0;
	
	if(descarte[contador_descarte].cor == 2  ) aux_cor[aux_contador] = cores[0];   		// passar o numero da cor a texto
	if(descarte[contador_descarte].cor == 3  ) aux_cor[aux_contador] = cores[1];    	
	if(descarte[contador_descarte].cor == 4  ) aux_cor[aux_contador] = cores[2];	
	if(descarte[contador_descarte].cor == 15 ) aux_cor[aux_contador] = cores[3];
	if(descarte[contador_descarte].cor == 14 ) aux_cor[aux_contador] = cores[4];
	
	if(descarte[contador_descarte].cor == 2  ) aux_cor[aux_contador_1] = cores[0];   		// passar o numero da cor a texto
	if(descarte[contador_descarte].cor == 3  ) aux_cor[aux_contador_1] = cores[1];    	
	if(descarte[contador_descarte].cor == 4  ) aux_cor[aux_contador_1] = cores[2];	
	if(descarte[contador_descarte].cor == 15 ) aux_cor[aux_contador_1] = cores[3];
	if(descarte[contador_descarte].cor == 14 ) aux_cor[aux_contador_1] = cores[4];
	
if(OPCAO == 2)
{
		
	for(i=0;i<3;i++)
	{
	gotoxy(91,15+i);printf("  ");
	}
	gotoxy(93,15+aux_contador);printf("                                                                                 ");
	setForeColor(6);
	gotoxy(91,15+aux_contador);printf("->");
	setForeColor(15);
	
	if (turno == 1 )
	{
	
	gotoxy(93,15+ aux_contador );printf("Foi");			setForeColor(12);
	printf(" descartada");								setForeColor(15);
	printf(" a %dª carta pelo ",pos+1);					setForeColor(11);
	printf("%s ", "BOT" );								setForeColor(15);
	printf(": %d",descarte[contador_descarte].num);		setForeColor(descarte[contador_descarte].cor);
	printf(" %s ", aux_cor[aux_contador] );				setForeColor(15);
	

	
	}
		
	if (turno == 0)
	{		
	gotoxy(93,15 + aux_contador );printf("Foi");
	setForeColor(12);
	printf(" descartada");
	setForeColor(15);
	printf(" a %dª carta pelo ",pos+1);
	setForeColor(11);
	printf("%s ", username);
	setForeColor(15);
	printf(": %d",descarte[contador_descarte].num);
	setForeColor(descarte[contador_descarte].cor);
	printf(" %s ", aux_cor[aux_contador] );	
	setForeColor(15);
	

		
	}
	
	aux_contador = aux_contador + 1 ;
		
	
	*aux_contador_descarte = aux_contador;
	
}

	
if (OPCAO==3 )
{
	for(i=0;i<3;i++)
	{
	gotoxy(91,21+i);printf("  ");
	}
	gotoxy(93,21+aux_contador_1);printf("                                                                                 ");
	setForeColor(6);
	gotoxy(91,21+aux_contador_1);printf("->");
	setForeColor(15);
	
	if ( turno == 1 )
	{
		
	gotoxy(93,21 + aux_contador_1);printf("Foi");			setForeColor(12);
	printf(" jogada e descartada");							setForeColor(15);
	printf(" a %dª carta pelo ",pos+1);						setForeColor(11);
	printf("%s ", username);								setForeColor(15);
	printf("(");											setForeColor(12);
	printf("-1 Vida");										setForeColor(15);
	printf(" ): %d",descarte[contador_descarte].num);		setForeColor(descarte[contador_descarte].cor);
	printf(" %s ", aux_cor[aux_contador_1] );				setForeColor(15);
	
	aux_contador_1 = aux_contador_1 + 1;
	}
	
	if (turno == 0)
	{
	gotoxy( 93,21 + aux_contador_1 ); printf("Foi");			setForeColor(12);
	printf(" jogada e descartada");							setForeColor(15);
	printf(" a %dª carta pelo ",pos+1);						setForeColor(11);
	printf("%s ", "BOT");								setForeColor(15);
	printf("(");											setForeColor(12);
	printf("-1 Vida");										setForeColor(15);
	printf(" ): %d",descarte[contador_descarte].num);		setForeColor(descarte[contador_descarte].cor);
	printf(" %s ", aux_cor[aux_contador_1] );				setForeColor(15);
	
	aux_contador_1 = aux_contador_1 + 1 ;	
	
	}
	 *aux_contador_jogadas  = aux_contador_1;
}

   

	
}
void escrever_descarte_opcao_2 ( carta descarte[] )		// escreve totalmente o descarte
{
	int j,i,cor,aux;
	int tamanho=0;// numero de cartas descartadas
	int soma[50];
	int num;
	
	
	for(i=0;i<50;i++)
	{
		soma[i] = 0;
	}
	i=0;
	
	while(descarte[i].num == 1 || descarte[i].num == 2 || descarte[i].num == 3|| descarte[i].num == 4|| descarte[i].num == 5)
	{
		soma[i] = 0;
		tamanho++;
		i++;
	}	

	

	
	for (j=0;j < tamanho; j++)
	{	
		for(i=0; i < tamanho;i++)
		{
			if(descarte[i].num == descarte [j].num && descarte[i].cor == descarte [j].cor)
			{
				soma[j] = soma[j] + 1 ;
			}
		}
	}
	
	
	grelha_discarte();
	
			
	for(i=0 ; i < tamanho ; i++)
	{	
		cor=descarte[i].cor;
		num=descarte[i].num;
			if (cor == 2)aux=1;									// Coordenada das cores
			if (cor == 3)aux=2;
			if (cor == 4)aux=3;
			if (cor == 15)aux=4;
			if (cor == 14)aux=5;	
			gotoxy(59+num,14+aux);
			printf("%d",soma[i]);	
	}
}
void adicionar_descarte (int opcao,int pos,carta J1[],carta J2[],carta deck[],carta descarte[],int turno,int *aux_contador_descarte,int *aux_contador_jogadas,char username[])// atualiza a grelha de discarde
{
	int aux,cor,num;// numero coluna |||| cor linha 
	int j=0;
	int i=0;
	int tamanho=0;
	pos=pos-1;
	
	while(descarte[i].num == 1 || descarte[i].num == 2 || descarte[i].num == 3|| descarte[i].num == 4|| descarte[i].num == 5)
	{
		tamanho++;
		i++;
	}
	
	
	switch (turno)
	{
	case 0 :{											// JOGADOR 1
	
	descarte[tamanho].num = J1[pos].num;			// descarte == J1
	descarte[tamanho].cor = J1[pos].cor;
	historico_descarte (opcao, descarte , aux_contador_descarte,aux_contador_jogadas, tamanho, turno, pos, username);
	darCarta(&J1[pos],deck);							
		break;
	}
	
	case 1:{											// BOT / J2
	descarte[tamanho].num = J2[pos].num;			// descarte == J2
	descarte[tamanho].cor = J2[pos].cor;
	historico_descarte ( opcao,descarte , aux_contador_descarte,aux_contador_jogadas, tamanho, turno, pos, username);
	darCarta(&J2[pos],deck);
		break;
	}
	}
	

	escrever_descarte_opcao_2(descarte);
	limparCarta(pos);
	mostrarDECK_1_POS(deck);
}
void print_pontuacao (int pontuacao)										//	exibe a pontuacao no ecra
{
	gotoxy(70,14);printf("Pontuação:");
	gotoxy(81,14);printf("%d",pontuacao);
}
void print_WhosNext    (int turn,char username[])				// Informacao do jogador que ira jogar
{
	gotoxy(45,2);printf("                            ");
	gotoxy(45,2);
	
	
	if(turn == 1)
	{
			printf("Turno do BOT ");
	}
	else
	{

		printf("Turno do %s ",username);
	}
}
void swap_player ( int *turno)									// troca os turnos
{
	int aux;
	aux = *turno;
	
	switch (aux)
	{
	case 0 : {
	aux = 1;
	break;
	}
	case 1: {
	aux = 0;
	break;
	}
	} 
 
 *turno = aux;
 
}
////void trocar_de_jogador (int turn, carta J1[], carta J2[], char username[])	// 	imprime de forma contraria as cartas
////{
////	
////
////	print_Player1_All_Cards(J1,turn,username);
////	
////	print_Player2_Cards (J2 ,turn);
////	
////	print_WhosNext(turn,username);
////	
////}
void escrever_pilha_na_mesa (int g,int b,int r,int w,int y)			// escreve as pilhas e o num da pilha na mesa
{
	showNumAt(7,17,g);
	showNumAt(12,17,b);
	showNumAt(17,17,r);
	showNumAt(22,17,w);
	showNumAt(27,17,y);
}
void pontuacao_mais_1 (int *p)                                    	// pontuacao +1
{
	int aux;
	aux=*p;
	aux=aux+1;
	*p=aux;
}
void historico_cartas_jogadas(int num ,int cor, int *aux_contador_jogadas,int pos,char username[]) // 
{
	
	int aux_contador = *aux_contador_jogadas;
	char* cores[]= {"verde","azul","vermelho","branco","amarelo"};
	char*aux_cor[5];
	int i=0;
	
	if(aux_contador == 3 || aux_contador < 0)aux_contador=0;
	
	if(cor == 2  ) aux_cor[aux_contador] = cores[0];   		// passar o numero da cor a texto
	if(cor == 3  ) aux_cor[aux_contador] = cores[1];    	
	if(cor == 4  ) aux_cor[aux_contador] = cores[2];	
	if(cor == 15 ) aux_cor[aux_contador] = cores[3];
	if(cor == 14 ) aux_cor[aux_contador] = cores[4];
	
	for(i=0;i<3;i++)
	{
		gotoxy(91,21+i);printf("  ");
	}
	
	gotoxy(93,21+aux_contador);printf("                                                                            ");
	setForeColor(6);
	gotoxy(91,21+aux_contador);printf("->");
	setForeColor(15);
	
	
	gotoxy(93,21+aux_contador);
	printf("Foi ");							setForeColor(10);
	printf("jogada");						setForeColor(15);
	printf(" a %d carta pelo",pos+1);		setForeColor(11);
	printf(" %s ",username);				setForeColor(15);
	printf("(");							setForeColor(10);
	printf("+1 pontuação");					setForeColor(15);
	printf(") : %d ",num);					setForeColor(cor);
	printf("%s ", aux_cor[aux_contador] );	setForeColor(15);
	
	aux_contador=aux_contador+1;
	
	
*aux_contador_jogadas = aux_contador;
}
void verificar_cor (int opcao,carta J1[],carta J2[],carta deck[],carta descarte[],int pos,int *red,int *blue,int *yellow,int *green,int *white,int *vidas,int pistas,int *pontuacao,int carta_jogada,int turno,char username[],int *aux_contador_descarte,int *aux_contador_jogadas) 
{
	int num,cor;
	int aux,i=0;
	int r,b,y,g,w;
	int tamanho;
	int aux_vidas = *vidas;
	g=*green;
	r=*red;
	b=*blue;
	y=*yellow;
	w=*white;
	
	i=0;	
	
	if (turno == 0)
{
	num=J1[pos-1].num;          			           
	cor=J1[pos-1].cor;								
	
	if ( cor == 2 )							     		//	green  J1
	{		
		if( num == g+1 )
		{
			*green=*green+1;
			g=*green;
			showNumAt(7,17,g);
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username);
			
			darCarta(&J1[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);
			aux=*pontuacao;
			print_pontuacao(aux);	
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		
		}
	}	
	if (cor ==3)										//	blue J1
	{
		if( num == b+1 )
		{
			*blue=*blue+1;
			b=*blue;
			showNumAt(12,17,b);
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username);
			darCarta(&J1[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);
			aux=*pontuacao;
			print_pontuacao(aux);
			
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;	
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}
	if (cor==4)											// 	Red J1
	{
		if( num == r+1 )
		{
			*red=*red+1;
			r=*red;
			showNumAt(17,17,r);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J1[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao;
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}
	if (cor==15)										// 	White  J1
	{ 
		if( num == w+1 )
		{
			*white=*white+1;
			w=*white;
			showNumAt(22,17,w);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J1[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);
			aux=*pontuacao;
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}	
	if (cor==14)										//	Yellow J1
	{
		if( num == y+1 )
		{
			*yellow=*yellow+1;
			y=*yellow;
			showNumAt(27,17,y);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J1[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao;
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}
}	
		/*     				 _                                      _                                
	     					| |                                    | |                               
	   				 _ __   | |   __ _    _   _   ___  _ __    ___ | |__    __ _  _ __    __ _   ___ 			em vez do player 1 joga o player 2
	   				| '_ \  | |  / _` |  | | | | / _ \| '__|  / __|| '_ \  / _` || '_ \  / _` | / _ \
 					| |_) | | | | (_| |  | |_| ||  __/| |    | (__ | | | || (_| || | | || (_| ||  __/
	  				| .__/  |_|  \__,_|  \__, | \___||_|     \___||_| |_| \__,_||_| |_| \__, | \___|
	  				| |                 __ / |                                          __/ |      
	   				|_|                |___/                                          |___/       */
	   			
if(turno == 1)
{
	num=J2[pos-1].num;   
	cor=J2[pos-1].cor;   
		
	if ( cor == 2 )							     		//	green J2
	{		
		if( num == g+1 )
		{
			*green=*green+1;
			g=*green;
			showNumAt(7,17,g);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J2[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao; 
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1; 
			 
			carta_jogada=0;
				*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}	
	if (cor == 3)										//	blue J2
	{
		if( num == b+1 )
		{
			*blue=*blue+1;
			b=*blue;
			showNumAt(12,17,b);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J2[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao; 
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}	
	if (cor== 4)											// 	Red J2
	{
		if( num == r+1 )
		{
			*red=*red+1;
			r=*red;
			showNumAt(17,17,r);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J2[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao; 
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1; 
			 
			carta_jogada=0;
			*vidas = aux_vidas;
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}
	if (cor == 15)										// 	White J2
	{
		if( num == w+1 )
		{
			*white=*white+1;
			w=*white;
			showNumAt(22,17,w);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username); 
			
			darCarta(&J2[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao; 
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1; 
			 
			carta_jogada=0;
			
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}	
	if (cor == 14)										//	Yellow J2
	{
		if( num == y+1 )
		{
			*yellow=*yellow+1;
			y=*yellow;
			showNumAt(27,17,y);
			
			carta_jogada=1;
			historico_cartas_jogadas( num , cor,  aux_contador_jogadas, pos, username);
			
			darCarta(&J2[pos-1],deck);	
			limparCarta(pos-1);
			mostrarDECK_1_POS(deck);
			pontuacao_mais_1(pontuacao);aux=*pontuacao; 
			print_pontuacao(aux);
		}
		else
		{
			adicionar_descarte(opcao,pos,J1,J2,deck,descarte,turno, aux_contador_descarte,aux_contador_jogadas,username);
			aux_vidas=aux_vidas-1;
			*vidas = aux_vidas;
			carta_jogada=0;
			 
			atualizar_VIDAS(pistas,aux_vidas);
		}
	}
	
}
}





#endif














