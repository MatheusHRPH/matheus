#include <stdio.h>
#include <time.h>>
#include <stdlib.h>
#define M 8  // pares de cartas
#define N 4  // tabuleiro 4x4 que armazena 16 cartas

char Tab[N][N], vA{'A'},vB{'B'},vC{'C'},vD{'D'},vE{'E'},vF{'F'},vG{'G'},vH{'H'};
char cartas[M] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char Verificar[M];
int pontos=0, acertos=0, v[8], y, jn;
void inicia_tab() {
	int x, cont, i, j;
	
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++) Tab[i][j]= 'Z';
	
	srand(time(NULL));
    x=0;
    cont=0;
	while (x<M){  // para cada elemento em V
		i=rand() % 4;
		j=rand() % 4;
		if (Tab[i][j] == 'Z') {
		   Tab[i][j] = cartas[x];
		   cont++;
	    }
		if (cont > 1) {
			x++;
		    cont = 0;
		}
	}	
}

void mostra_tab() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo  -----\n\n");
	printf("!!! 10 segundos para decorar !!!\n\n");
	for(i=0; i<N; i++) {
	  for(j=0; j<N; j++) 
	      printf ("%c  ", Tab[i][j]);
	  printf("\n");
    }
}

void esconde_tab() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo Escondido  -----\n\n");
	 for(i=0; i<N; i++) {
	  	for(j=0; j<N; j++)
	  		printf("[%d %d]  ",i+1,j+1);
	  	 printf("\n");	
}
}
int jogada_tab() {
	int i, j, l1, c1, l2, c2;
	char a1, b1;
	for(y=0;y<8;y++){
		v[y]=0;
	}
		
	while(acertos!=8){
			
			
		printf("\n-----Escolher primeira Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 4)\n");
		scanf("%d", &l1);
		printf("Digite a Coluna da Carta (1 a 4)\n");
		scanf("%d", &c1);
		a1=Tab[l1-1][c1-1];
			for(i=0; i<N; i++) {
	  			for(j=0; j<N; j++)
	  				if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tab[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
					  printf("\n"); 
				}
		printf("-----Escolher segunda Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 4)\n");
		scanf("%d", &l2);
		printf("Digite a Coluna da Carta (1 a 4)\n");
		scanf("%d", &c2);
		b1=Tab[l2-1][c2-1];
			for(i=0; i<N; i++) {
	  			for(j=0; j<N; j++)
	  				if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tab[i][j]);
	  				else if(i==l2-1&&j==c2-1)
	  				  printf ("   %c   ", Tab[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
					  printf("\n");	
					  
				}
				system("cls");
				if(a1==b1){
					if(a1==vA){
					v[0]++;
					y=0;
				}
					if(a1==vB){
					v[1]++;
					y=1;
				}
					if(a1==vC){
					v[2]++;
					y=2;
				}
					if(a1==vD){
					v[3]++;
					y=3;
				}
					if(a1==vE){
					v[4]++;
					y=4;
				}
					if(a1==vF){
					v[5]++;
					y=5;
				}
					if(a1==vG){
					v[6]++;
					y=6;
				}
					if(a1==vH){
					v[7]++;
					y=7;
				}
					
				
				if(v[y]>1){
					 
						printf("LETRA {%c} JA ENCONTRADA ANTERIORMENTE!!!\n\n", a1);
						printf("%d/8 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tab[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tab[i][j]);
							 else printf("[%d %d]  ",i+1,j+1);
							  printf("\n");
						}
						system("pause");

						}
					
					else{
					 printf("ACERTOU!!! (Letra %c)  (+15 Pontos)\n", a1);
					acertos++;
					pontos=pontos+15;
					for(i=0; i<N; i++) {
	  					for(j=0; j<N; j++)
	  						if(i==l1-1&&j==c1-1){
							  	Tab[i][j]=a1;
							  	printf ("   %c   ", Tab[i][j]);
							  }
							else if(i==l2-1&&j==c2-1){
								Tab[i][j]=b1;
								 printf ("   %c   ", Tab[i][j]);
							}
							else printf("[%d %d]  ",i+1,j+1);
					  			printf("\n");
										}
						printf("%d/8 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
										
						
		
		
			
	}
}
				 else{
				  printf("ERROU!!! (Letras %c e %c)  (-3 Pontos)\n", a1,b1);
				 pontos=pontos-3;
			printf("%d/8 Pares\n\n",acertos);
			printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tab[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tab[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							  printf("\n");
			}


}
printf("\n\n");
printf("\nVoce ja achou a(s) letra(s):");
if(v[0]>0) printf("A ");
if(v[1]>0) printf("B ");
if(v[2]>0) printf("C ");
if(v[3]>0) printf("D ");
if(v[4]>0) printf("E ");
if(v[5]>0) printf("F ");
if(v[6]>0) printf("G ");
if(v[7]>0) printf("H ");
printf("\n\n");
printf("\nFaltam a(s) letra(s):");
if(v[0]==0) printf("A ");
if(v[1]==0) printf("B ");
if(v[2]==0) printf("C ");
if(v[3]==0) printf("D ");
if(v[4]==0) printf("E ");
if(v[5]==0) printf("F ");
if(v[6]==0) printf("G ");
if(v[7]==0) printf("H ");
printf("\n\n");
}


}

int dificil() {
	printf("Voce escolheu o jogo Dificil\n\n");
	printf("Nesse modo voce precisa achar todos os 8 pares para vencer\n\n");
	printf("A cada acerto voce ganha 15 pontos, a cada erro voce perde 3 pontos\n\n");
	printf("Os numeros nas cartas representam a posicao das cartas\n\n");
	printf("O PRIMEIRO numero representa a LINHA e o SEGUNDO representa a  COLUNA\n\n");
	printf("Para escolher uma carta voce deve digitar o numero da LINHA e confirmar\n\n");
	printf("Em seguida voce deve digitar o numero da COLUNA e confirmar\n\n");
	printf("Quando estiver pronto aperte ENTER para iniciar, BOA SORTE \n\n");
	system("pause");
	system("cls");
	inicia_tab();
	mostra_tab();
	_sleep(10000);
	system("cls");
	esconde_tab();
	jogada_tab();
	printf("------VOCE VENCEU!!!------\n\n");
	printf("------TOTAL DE PONTOS: %d ------\n\n",pontos);
	
		
    	
}

	

int main(){
	int e;
	printf("Escolha uma Dificuldade: Facil (1) Dificil (2)\n");
	scanf("%d",&e);
	if(e==2){
		system("cls");
		dificil();
	}
	printf("Quer Jogar novamente? Sim(1) Nao(2)\n");
	scanf("%d",&jn);
	pontos=0;
	acertos=0;
	if(jn==1){
		system("cls");
	 dificil();
}
	if(jn==2) return 0;
	return 0;
}

