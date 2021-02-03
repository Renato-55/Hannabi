#ifndef _DECKH_	//protectes from multiple including...
#define _DECKH_		//... needs an #endif at bottom

#include "global.h"
#include "Header.h"



int criarDECK (carta deck[])							// Atribui cores e numeros as cartas
{
	int random[50] ;
	int i=0,j=0,z=0,aux=0,contador=0;
	
	for (j=0;j<NUMERODECORES;j++)			   			// dar um numero para a carta
	{
	for (i=0;i<CARTASPORCOR;i++)
	{
		if (i!=0){
		aux=(i%2)+i/2;
		deck[i+j*10].num=aux;		
		}
		else
		{
		deck[i+j*10].num=1;
		}
		}
	}
	
	for (j=0;j<NUMERODECORES;j++)						// dar um numero para a cor
	{
		for (i=0;i<CARTASPORCOR;i++)
		{
		if (i==0 && j==0 ){
			deck[0].cor=2;
		}
		else
		{
			switch (j)
		{
		case 0:
			{
			 deck[i+j*10].cor = 2;
			 break;
			}
		case 1:
			{
			 deck[i+j*10].cor = 3;
			 break;
			}
		case 2:
			{
			 deck[i+j*10].cor = 4;
			 break;
			}
		case 3:
			{
			 deck[i+j*10].cor = 15;
			 break;
			}
		case 4:
			{
			 deck[i+j*10].cor = 14;
			 break;
			}
		}		
		}
	}
	}
	
return 0;	
}
int baralhar (carta deck[]) 							// baralha o baralho aleatoriamente
{
	int i=0,j=0;
	int auxiliar,auxiliar1;
	int random[50];
	int aux[i];
	
	srand(time(NULL));
	
	for (i=0;i<50;i++)									// DISTRIBUI NUMEROS ALEATORIOS AO VEOTR RANDOM
	{
		aux[i]=rand () % 50;
		random[i]=aux[i];
	}

	
	for (i=0;i<TOTALCARTAS;i++)							// DA VALORES DIFERENTES ENTRE 0 E 49
	{
	for (j=i+1;j<TOTALCARTAS;j++)
	{
		if (random[i] == random[j] )
		{
			random[i] = rand () % 50;
			i=-1;
			break;
		}			
	}	
	}
	j=49;
	for (i=0;i<TOTALCARTAS;i++)							//  O DECK ( COR E NUM ) ja estao sincronizados e sem erros
	{

	auxiliar=deck[random[i]].num;
	deck[random[i]].num=deck[j].num;
	deck[j].num=auxiliar;
	
	auxiliar1=deck[random[i]].cor;
	deck[random[i]].cor=deck[j].cor;
	deck[j].cor=auxiliar1;
	
	j--;
	}
	return 0;	
}
void showCartaAt (int x, int y, int c,int d) 			// Imprimi um carta na posicao x,y 
{	
	setForeColor(c);									// Imprimi um carta na posicao x,y 
	showRectAt(x,y,4,4);
	gotoxy(x+2,y+2);
	setForeColor(15);
	printf("%d",d);
	resetColor (0);
}
void destruirCarta (carta *deck)						// o num e a cor da ultima carta sao colocados a 0 ( associada à funcao darCarta) 
{
	deck[49].num=0;
	deck[49].cor=0;
	deck[49].jogavel_num=0;
	deck[49].jogavel_cor=0;
}
void darCarta (carta *c,carta deck[])					// o vetor das cartas anda 1 posicao para a esquerda e a posicao 49 é colocada a 0
{
	int aux_num;
	int aux_cor;
	int i=0;
	
	(*c).num=deck[0].num;								// a primeira carta do deck vai pertence á 1 entrada da funcao
	(*c).cor=deck[0].cor;
	(*c).jogavel_num = 0;
	(*c).jogavel_cor = 0;
	
	for (i=0;i<49;i++)									// roda as cartas todas 1 posicao
	{															
		deck[i].num=deck[i+1].num;
		deck[i].cor=deck[i+1].cor;		
	}
	
	
	destruirCarta(deck);								// ultima carta fica com o NUM !! e a COR !! a 0 !!
}
int CaraCoroa(char username[],int turno) // vai gerar um numero aleatorio entre 1 e 0 para defenir quem comeca a jogar
{		
	gotoxy(45,2);
	if(turno == 1)
	{
		printf("O BOT começa ");
	}
	else
	{
		printf("O %s começa",username);
	}
 }
void print_Player1_All_Cards ( carta J1 [],int turno,char username[]) // imprime as  carta do jogador 1
{
	int i=0,j=49;
	int cor,numero;
	
////	if (turno == 1)
////	{
////	for (i=0;i<HANDSIZE;i++)
////	{
////	J1[i].vis=1;
////	}
////	}
////	else
////	{
////	for (i=0;i<HANDSIZE;i++)
////	{
////	J1[i].vis=0;
////	}
////	}
	
	for (i=0;i<5;i++)
	{
////	if (J1[i].vis == 1)
////	{
////		cor    = 	J1[i].cor;
////		numero =	J1[i].num;
////		showCartaAt(5+i*5,	5, cor ,numero);	
////	}
//	else
//	{
		setForeColor(8);
		showRectAt(5+i*5,5,4,4);
		gotoxy(7+i*5,7);
		printf("%c",169);
		resetColor();							
//	}	
	}	
	
	gotoxy(13,4);printf("%s",username);
}
int Player1 (carta J1[] ,carta deck[],char username[],int turno) // JOGADOR 1
{	
	int i=0;
	
	for (i=0;i<HANDSIZE;i++)
	{
	darCarta(&J1[i],deck);
	}
	
	print_Player1_All_Cards(J1,turno,username);
	
	return 0;
}
void print_Player2_Cards (carta J2 []) // imprime as cartas do bot
{
	int i=0,j=49;
	int cor,numero;
	
	
////	if (turno == 1)
////	{
////	for (i=0;i<HANDSIZE;i++)
////	{
////	J2[i].vis=0;
////	}
////	}
////	else
////	{
////	for (i=0;i<HANDSIZE;i++)
////	{
////	J2[i].vis=1;
////	}
////	}
	
	
	for (i=0;i<HANDSIZE;i++)
	{
		
////	if (J2[i].vis == 1)
////	{
		cor=J2[i].cor;
		numero=J2[i].num;
		showCartaAt(5+i*5,	25, cor ,numero);	
////	}
////	else
////	{
////		setForeColor(8);
////		showRectAt(5+i*5,25,4,4);
////		gotoxy(7+i*5,27);
////		printf("%c",169);
////		resetColor();							
////	}	
	}
	
	gotoxy(15,30);printf(" BOT ");
}
int Player2 (carta J2[] ,carta deck[]) //				 BOT
{	
	int i=0;
	for (i=0;i<HANDSIZE;i++)
	{
		darCarta(&J2[i],deck);
	}
	print_Player2_Cards ( J2 );
	
	return 0;
}
void mostrarDECK_1_POS(carta deck[]) // 	numero de cartas disponiveis para jogar
{
	int i=0;
	int contador=0;
	
	setForeColor(8);
	showRectAt(37,15,4,4);
	gotoxy(39,17);printf("%c",169);		//  Imprime o simbolo da parte traseira das cartas
	resetColor();
		
	while(deck[i].num != 0 && deck[i].cor != 0)
	{
		i++;
		contador++;
	}
	
	setForeColor(15);
	gotoxy(32,13);printf("Cartas restantes: ");
	setForeColor(11);
	gotoxy(50,13);printf("    ");gotoxy(50,13);printf("%d",contador); // Digita o numero de cartas
	setForeColor(15);
	
}
void cartasParaA_Mesa() // lugares reservados para as cartas que irao ser jogadas
{
	int i=0;
	int cores[] = {2,3,4,15,14};
	
	for (i=0;i<5;i++)
	{
	setForeColor(cores[i]);
	showRectAt(5+i*5,15,4,4);
	gotoxy(7+i*5,15);
	resetColor();	
	}
	
}


#endif
