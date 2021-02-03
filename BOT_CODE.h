#ifndef _BOT_CODEH_	//protectes from multiple including...
#define _BOT_CODEH_	//... needs an #endif at bottom


#include "menus.h"


void primeira_condicao_BOT (carta J1[],int *turno,int *pistas , int vidas,char nome[], int pontuacao , int *aux_contador_pistas , carta descarte [],int *BOT_jogou) // corrigir erros amanha 15/01/2020
{
	int i=0;
	int pos=0;
	int numero=0;
	int aux_pistas = *pistas;
	int aux_turno = *turno;
	int aux_contador = *aux_contador_pistas;
	int verdade=0;
	pos=0;
	
	while(descarte[i].num !=0 )
	{
		
	i++;	
	}
	
	
	if(aux_pistas == 8 && pontuacao == 0 && vidas == 3 && i == 0 )
	{	
	for (i=0;i<5;i++)
	{
		if(J1[i].num == 1 ) 
		{
		pos=i;	
		numero=J1[i].num;
		showNumAt(i*5+7,7,numero);
		verdade=1;							
		}
	}
	
	if(	verdade == 1 ) 
	{		
	
			if(aux_contador == 3 || aux_contador<0 )aux_contador=0;
			gotoxy(93,9 + aux_contador);printf("                                                                            ");
			setForeColor(6);
			gotoxy(91,9 + aux_contador);printf("->");
			setForeColor(15);
	
			gotoxy(93,9+aux_contador);printf("Pista para o ");
			setForeColor(11);
			printf("%s ", nome);
			setForeColor(15);
			printf("sobre o número da %dª carta = %d ", pos+1 , J1[pos].num);
			
			
			aux_contador=aux_contador+1;
			aux_pistas=aux_pistas-1;
			
			*aux_contador_pistas = aux_contador;
	
			*pistas = aux_pistas;
	}
	
	atualizar_VIDAS(aux_pistas,vidas);
	}
	if(verdade == 1)
	{
		*BOT_jogou = 1;
	}

}
void segunda_condicao_BOT (carta J2[] , int *green ,int *red ,int *blue ,int *yellow ,int *white,char username[], int *aux_contador_jogadas,carta deck[],int *pontuacao,int *BOT_jogou)
{
	int possivel_jogar[5];
	int numeros[5];
	int i=0,j=0;
	int cor=0;
	int coordenada =0;
	int aux_pontuacao  = *pontuacao;
	int sair = 0;
	
	int aux_BOT = *BOT_jogou;
	
	int g = *green;
	int b = *blue;
	int r = *red;
	int w = *white;
	int y = *yellow;
	

	sair = 0;

if(aux_BOT == 0)
{
	for(i=0;i<5;i++)
	{
		if(J2[i].jogavel_num == 1)
		{
			if(J2[i].jogavel_cor == 1)
			{
					if(J2[i].cor == 2) {cor=g ; coordenada=0; }
					if(J2[i].cor == 3) {cor=b ; coordenada=1; }
					if(J2[i].cor == 4) {cor=r ; coordenada=2; }
					if(J2[i].cor == 15){cor=w ; coordenada=3; }
					if(J2[i].cor == 14){cor=y ; coordenada=4; }
					
						if(J2[i].num == cor+1 && sair == 0)// entrou na pilha 
						{
						
						cor=cor + 1 ;
						showNumAt( 7 + coordenada * 5  , 17 , cor );
						historico_cartas_jogadas( cor , J2[i].cor ,  aux_contador_jogadas, i+1, "BOT"); // esta cor é o numero das pilhas !!! 
						darCarta(&J2[i],deck);
						print_Player2_Cards ( J2 );
						mostrarDECK_1_POS(deck);
						pontuacao_mais_1(pontuacao);
						print_pontuacao(aux_pontuacao);
						
						
						if (coordenada == 0){ g=g+1; *green  = g;}
						if (coordenada == 1){ b=b+1; *blue   = b;}
						if (coordenada == 2){ r=r+1; *red    = r;}
						if (coordenada == 3){ w=w+1; *white  = w;}
						if (coordenada == 4){ y=y+1; *yellow = y;}
						
						sair++;
						}					
			}
		}
	}
}

	if(sair != 0)
	{
		*BOT_jogou = 1;	
	}	
}
void terceira_condicao_BOT ( carta J1[] ,carta J2[], int turno,int *aux_contador_pistas, char username[],int green ,int red ,int blue ,int yellow ,int white ,int *pistas,int vidas, int *BOT_jogou)
{
srand(time(NULL));

int i,j;
int aux_pistas = *pistas;
int cores[5]={2,3,4,15,14};
int num_da_pilha[5]={green,blue,red,white,yellow};
int carta_jogavel[5];
int sair = 0;
int numero;
int cor;

int menor = J1[0].num;
int pos_menor ;

int aux_rand_cor;

int aux_BOT = *BOT_jogou;

sair = 0;



for(j=1;j<5;j++) // ve qual é o menor num 
{
	if(J1[j].num < menor)
	{
	menor = J1[j].num;
	pos_menor = j;
	}
}


if(aux_pistas > 0 && aux_BOT == 0)
{
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(J1[i].cor == cores[j] )
			{
				if(J1[i].num == num_da_pilha[j] + 1 )
				{
				carta_jogavel[i] = 1; 
				}
				else
				{
				carta_jogavel[i] = 0;
				}
			}
		}
	}
	
	for(i=0;i<5;i++)
	{	
		if(carta_jogavel[i] == 1 && sair == 0)
		{
			if (J1[i].jogavel_num == 1 )
			{
				if(J1[i].jogavel_cor == 1) // nao da pista
				{
					
				}
				else			// da a pista de uma cor
				{
					if(J1[i].jogavel_cor == 0)
					{
						for(j=0;j<5;j++)
						{
							if (J1[j].cor == J1[i].cor)		// da pistas sobre todos as cores iguais 
							{
							J1[j].jogavel_cor = 1; 	
							cor=J1[j].cor;
							setForeColor(cor);
							showRectAt(5+j*5,5,4,4);
							resetColor();						
							sair ++;
						
							if(sair == 1){ historico_pistas ( J1 , J2 , i+1 ,  username , aux_contador_pistas, 0 , 2 );	}
						
							}
						}
					}			
				}
			}
			else	// vai dar a pista de um numero 
			{
				if(J1[i].jogavel_num == 0 )	
				{
					for (j=0;j<5;j++)
					{
						if (J1[j].num == J1[i].num) // da pistas sobre todos os num iguais 
						{
						
						J1[j].jogavel_num = 1; 	
						numero=J1[j].num;
						showNumAt(j*5+7,7,numero);
					
						sair ++ ;
					
						if(sair == 1) { historico_pistas ( J1 , J2 , i+1 ,  username , aux_contador_pistas, 0 , 1 );	}
						}
					} 
				}
			}		
		}
		else
		{
			if(sair != 0)
			{
				if(J1[i].jogavel_num == 0 && carta_jogavel[i] == 0 && sair == 0) // numero nao jogavel e desconhecido para o jogador 1
				{				
					for (j=0;j<5;j++)
					{
						if (J1[j].num == menor) // da pistas sobre todos os num iguais 
						{
						J1[j].jogavel_num = 1; 	
						showNumAt(j*5+7,7,menor);
					
						sair ++ ;
					
						if(sair == 1) { historico_pistas ( J1 , J2 , pos_menor+1 ,  username , aux_contador_pistas, 0 , 1 );	}
						}
					} 
				}
			}
		}
	}
}



		for (i=0;i<5;i++)// dizer cor aleatoria 
		{
			if(J1[i].jogavel_cor == 0 &&carta_jogavel[i] == 0  && sair == 0 && aux_pistas > 0 && aux_BOT == 0)
			{
				
				do
				{
					aux_rand_cor = rand () % 5;	
											
				}while(J1[aux_rand_cor].jogavel_cor == 1);
			
				
				for(j=0;j<5;j++)
				{
					if (J1[j].cor == J1[aux_rand_cor].cor)		// da pistas sobre todos as cores iguais 
					{
					J1[j].jogavel_cor = 1; 	
					cor=J1[j].cor;
					setForeColor(cor);
					showRectAt(5+j*5,5,4,4);
					resetColor();						
					sair ++;
						
					if(sair == 1){ historico_pistas ( J1 , J2 , aux_rand_cor+1 ,  username , aux_contador_pistas, 0 , 2 );	}
					}
				}	
			}
		}






		if( sair != 0)				// se deu a pista vai as atualizar
		{
		aux_pistas = aux_pistas - 1; 
		atualizar_VIDAS(aux_pistas,vidas);
		
		*BOT_jogou = 1;	
		}








*pistas = aux_pistas;

}
void quarta_condicao_BOT (carta J1[] , carta J2[] ,carta descarte[], int *aux_contador_descarte , int * BOT_jogou, int *pistas, int vidas  , int *aux_contador_jogadas, carta deck[],int green ,int red ,int blue ,int yellow ,int white )
{
	int aux_BOT = *BOT_jogou;
	int aux_pistas = *pistas;
	int i=0,j=0;
	int sair = 0;
	int menor = J1[0].num;
	int pos_menor; 

	int cores[5]={2,3,4,15,14};
	int num_da_pilha[5]={green,blue,red,white,yellow};
	int carta_descartavel[5];
	int aux_rand;
	
	
	for (i=0;i<5;i++)
	{
		if(J2[i].jogavel_cor == 1 && J2[i].jogavel_num == 1)
		{
			for(j=0;j<5;j++)
			{
				if(J2[i].cor == cores[j] )
				{
					if(J2[i].num <= num_da_pilha[j]  ) // averigua se a carta é conhecida e pode ser descartavel
					{
					carta_descartavel[i] = 1; 
					}
					else
					{
					carta_descartavel[i] = 0;
					}
				}
			}
		}
		else
		{
			carta_descartavel[i] = 0;	
		}
	}
	
	
	
	
		sair = 0;
	
	if( aux_BOT == 0 )
	{
		for(i=0;i<5;i++)
		{
			if(J2[i].jogavel_num == 0 && J2[i].jogavel_cor == 0 && sair == 0) // descarta carta desconhecida || num e cor ||
			{
				descartar_uma_carta (2 , i+1 , J1, J2, deck, descarte,  0 , pistas, vidas , aux_contador_descarte , aux_contador_jogadas,"BOT");
				sair++ ;
			}
			else
			{
				if( sair == 0 && J2[i].jogavel_num == 1 && carta_descartavel[i] == 1) // descarta carta desnecesaria
				{
					descartar_uma_carta (2 , i+1 , J1, J2, deck, descarte,  0 , pistas, vidas , aux_contador_descarte , aux_contador_jogadas,"BOT");
					sair++;
				}
				else
				{
					if(( J2[i].jogavel_num == 1 ||  J2[i].jogavel_cor == 1) && sair == 0 )
					{
						do
						{
						aux_rand = rand() % 5 ;
						}while(J2[i].jogavel_num == 0 && J2[i].jogavel_cor == 0);
						descartar_uma_carta (2 , aux_rand + 1 , J1, J2, deck, descarte,  0 , pistas, vidas , aux_contador_descarte , aux_contador_jogadas,"BOT");
						sair++;
					}
				}
			}
		}
	}


}	
	
















#endif
