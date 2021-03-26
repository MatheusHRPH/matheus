#include <stdio.h>
#include <time.h>>
#include <stdlib.h>
#define M 8 
#define N 4  
#define J 6
#define D 18
char Tabfacil[N][N], fA{'A'},fB{'B'},fC{'C'},fD{'D'},fE{'E'},fF{'F'},fG{'G'},fH{'H'};
char cartasfacil[M] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char Tabdificil[J][J], vA{'A'},vB{'B'},vC{'C'},vD{'D'},vE{'E'},vF{'F'},vG{'G'},vH{'H'},vI{'I'},vJ{'J'},vK{'K'},vL{'L'},vM{'M'},vN{'N'},vO{'O'},vP{'P'},vQ{'Q'},vR{'R'};
char cartasdificil[D] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
int pontos=0, acertos=0, v[18], y, jn;

float **alocarmatriz( int n, int m){
	float **Mat;
	int i;
	Mat = (float **) malloc(n*sizeof(float *));
	if(Mat==NULL) {
		printf("Erro ao alocar memoria\n");
		exit(-1);
	}
	for(i=0; i<n; i++){
		Mat[i]= (float *) malloc(m*sizeof(float));
		if (Mat[i]== NULL){
			printf("Erro ao alocar memoria\n");
			exit(-1);
			
		}
	}
	printf("Matriz alocada com sucesso\n");
	return Mat;
}
void zeramatriz(float **x, int n, int m){
	int i, j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++) x[i][j]=0;
		printf("Matriz inicializada com sucesso\n");
}
void liberarmatriz(float **x, int n){
	int i;
	for(i=0;i<n;i++)
		if(x[i]!=NULL) free(x[i]);
	free(x);
	printf("Memoria liberada com sucesso");
}

void inicia_tabfacil() {
	int x, cont, i, j;
	
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++) Tabfacil[i][j]= 'Z';
	
	srand(time(NULL));
    x=0;
    cont=0;
	while (x<M){  
		i=rand() % 4;
		j=rand() % 4;
		if (Tabfacil[i][j] == 'Z') {
		   Tabfacil[i][j] = cartasfacil[x];
		   cont++;
	    }
		if (cont > 1) {
			x++;
		    cont = 0;
		}
	}	
}

void mostra_tabfacil() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo  -----\n\n");
	
	for(i=0; i<N; i++) {
	  for(j=0; j<N; j++) 
	      printf ("%c  ", Tabfacil[i][j]);
	  printf("\n");
    }
}

void esconde_tabfacil() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo Escondido  -----\n\n");
	 for(i=0; i<N; i++) {
	  	for(j=0; j<N; j++)
	  		printf("[%d %d]  ",i+1,j+1);
	  	 printf("\n");	
}
}
int jogada_tabfacil() {
	int i, j, l1, c1, l2, c2, acertoufacil[4][4];
	char a1, b1;
	for(y=0;y<8;y++){
		v[y]=0;
	}
	for(i=0; i<N; i++) {
	  	for(j=0; j<N; j++)
	  	 acertoufacil[i][j]=0;
}
acertos=0;
pontos=0;
	while(acertos!=8){
			
			
		printf("\n-----Escolher primeira Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 4)\n");
		scanf("%d", &l1);
		printf("Digite a Coluna da Carta (1 a 4)\n");
		scanf("%d", &c1);
		system("cls");
		printf("Voce Escolheu a Carta [%d %d] e revelou a letra %c\n\n", l1, c1, Tabfacil[l1-1][c1-1]);
		a1=Tabfacil[l1-1][c1-1];
			for(i=0; i<N; i++) {
	  			for(j=0; j<N; j++)
	  				if(acertoufacil[i][j]==1)
	  					printf("   %c   ", Tabfacil[i][j]);
	  				 else{
					   if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tabfacil[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
					  }
					  printf("\n"); 
				
				}
				
		printf("-----Escolher segunda Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 4)\n");
		scanf("%d", &l2);
		printf("Digite a Coluna da Carta (1 a 4)\n");
		scanf("%d", &c2);
		
		b1=Tabfacil[l2-1][c2-1];
			for(i=0; i<N; i++) {
	  			for(j=0; j<N; j++)
	  				if(acertoufacil[i][j]==1)
	  					printf("   %c   ", Tabfacil[i][j]);
	  				 else {
					   if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tabfacil[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
	  			}
					  printf("\n");	
			}
			system("cls");
			if(l1==l2&&c1==c2) {
			printf("Jogada Invalida\n\n");
			system("pause");
			system("cls");
			for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							printf("\n");	
		}
	}
			else 	if(a1==b1){
					if(a1==vA){
					v[0]++;
					y=0;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vB){
					v[1]++;
					y=1;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vC){
					v[2]++;
					y=2;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vD){
					v[3]++;
					y=3;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vE){
					v[4]++;
					y=4;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vF){
					v[5]++;
					y=5;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vG){
					v[6]++;
					y=6;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					if(a1==vH){
					v[7]++;
					y=7;
					acertoufacil[l1-1][c1-1]=1;
					acertoufacil[l2-1][c2-1]=1;
				}
					
				
				if(v[y]>1){
					 
						printf("LETRA {%c} JA ENCONTRADA ANTERIORMENTE!!!\n\n", a1);
						printf("%d/8 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
	  							else{
							  
							  if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tabfacil[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tabfacil[i][j]);
							 else printf("[%d %d]  ",i+1,j+1);
							  }
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
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
							  
							  else{
							  if(i==l1-1&&j==c1-1){
							  	Tabfacil[i][j]=a1;
							  	printf ("   %c   ", Tabfacil[i][j]);
							  }
							else if(i==l2-1&&j==c2-1){
								Tabfacil[i][j]=b1;
								 printf ("   %c   ", Tabfacil[i][j]);
							}
							else printf("[%d %d]  ",i+1,j+1);
					  			}
								  printf("\n");
					  		
										}
						printf("%d/8 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
						system("pause");
						system("cls");									
						for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							printf("\n");	
						}
		
		
			
	}
}
				 else{
				  printf("ERROU!!! (Letras %c e %c)  (-3 Pontos)\n", a1,b1);
				 pontos=pontos-3;
			printf("%d/8 Pares\n\n",acertos);
			printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
							  else{
							  if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tabfacil[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tabfacil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							  }
							  printf("\n");
						
			}
			system("pause");
			system("cls");
			for(i=0; i<N; i++) {
	  						for(j=0; j<N; j++)
	  						if(acertoufacil[i][j]==1)
	  							printf("   %c   ", Tabfacil[i][j]);
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

system("pause");
}

void facil() {
	int tempo=10;
	float **MA;
	MA=alocarmatriz(4,4);
	zeramatriz(MA, 4, 4);
	system("pause");
	system("cls");
	printf("Voce escolheu o jogo Facil\n\n");
	printf("Quando estiver pronto aperte ENTER para iniciar, BOA SORTE \n\n");
	system("pause");
	system("cls");
	inicia_tabfacil();
	while(tempo!=0){
	printf(" ----  Tabuleiro do Jogo  -----\n\n");
	printf("%d Segundos para decorar\n\n",tempo);
	mostra_tabfacil();
	_sleep(1000);
    system("cls");
    tempo=tempo-1;
}
	esconde_tabfacil();
	jogada_tabfacil();
	system("cls");
	liberarmatriz(MA, 4);
	system("pause");
	system("cls");
	printf("------VOCE VENCEU!!!------\n\n");
	printf("------TOTAL DE PONTOS: %d ------\n\n",pontos);
	printf("Para voltar ao Menu Principal aperte ENTER \n\n");
}
void inicia_tabdificil() {
	int x, cont, i, j;
	
	for(i=0; i<J; i++)
	  for(j=0; j<J; j++) Tabdificil[i][j]= 'Z';
	
	srand(time(NULL));
    x=0;
    cont=0;
	while (x<D){  
		i=rand() % 6;
		j=rand() % 6;
		if (Tabdificil[i][j] == 'Z') {
		   Tabdificil[i][j] = cartasdificil[x];
		   cont++;
	    }
		if (cont > 1) {
			x++;
		    cont = 0;
		}
	}	
}

void mostra_tabdificil() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo  -----\n\n");
	for(i=0; i<J; i++) {
	  for(j=0; j<J; j++) 
	      printf ("%c  ", Tabdificil[i][j]);
	  printf("\n");
    }
}

void esconde_tabdificil() {
	int i, j;
	printf(" ----  Tabuleiro do Jogo Escondido  -----\n\n");
	 for(i=0; i<J; i++) {
	  	for(j=0; j<J; j++)
	  		printf("[%d %d]  ",i+1,j+1);
	  	 printf("\n");	
}
}
int jogada_tabdificil() {
	int i, j, l1, c1, l2, c2, acertoudificil[6][6];
	char a1, b1;
	for(y=0;y<18;y++){
		v[y]=0;
	}
	for(i=0; i<6; i++) {
	  	for(j=0; j<6; j++)
	  	 acertoudificil[i][j]=0;
	  }
	acertos=0;	
	pontos=0;
	while(acertos!=18){
			
			
		printf("\n-----Escolher primeira Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 6)\n");
		scanf("%d", &l1);
		printf("Digite a Coluna da Carta (1 a 6)\n");
		scanf("%d", &c1);
		system("cls");
		printf("Voce Escolheu a Carta [%d %d] e revelou a letra %c\n\n", l1, c1, Tabdificil[l1-1][c1-1]);
		a1=Tabdificil[l1-1][c1-1];
			for(i=0; i<J; i++) {
	  			for(j=0; j<J; j++)
	  				if(acertoudificil[i][j]==1)
	  					printf("   %c   ", Tabdificil[i][j]);
	  				else{	
					  if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tabdificil[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
			}
				   printf("\n"); 
				}
		printf("-----Escolher segunda Carta-----\n");
		printf("Digite a Linha da Carta( 1 a 4)\n");
		scanf("%d", &l2);
		printf("Digite a Coluna da Carta (1 a 4)\n");
		scanf("%d", &c2);
		b1=Tabdificil[l2-1][c2-1];
			for(i=0; i<J; i++) {
	  			for(j=0; j<J; j++)
	  				if(acertoudificil[i][j]==1)
	  					printf("   %c   ", Tabdificil[i][j]);
					  else{
					  if(i==l1-1&&j==c1-1)
	  				  printf ("   %c   ", Tabdificil[i][j]);
	  				else if(i==l2-1&&j==c2-1)
	  				  printf ("   %c   ", Tabdificil[i][j]); 
	  				else printf("[%d %d]  ",i+1,j+1);
			}
				   printf("\n");	
					  
				}
				system("cls");
					if(l1==l2&&c1==c2) {
			printf("Jogada Invalida\n\n");
			system("pause");
			system("cls");
			for(i=0; i<J; i++) {
	  						for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							printf("\n");	
		}
	}
			else	if(a1==b1){
					if(a1==vA){
					v[0]++;
					y=0;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vB){
					v[1]++;
					y=1;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vC){
					v[2]++;
					y=2;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vD){
					v[3]++;
					y=3;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vE){
					v[4]++;
					y=4;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vF){
					v[5]++;
					y=5;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vG){
					v[6]++;
					y=6;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vH){
					v[7]++;
					y=7;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vI){
					v[8]++;
					y=8;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vJ){
					v[9]++;
					y=9;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vK){
					v[10]++;
					y=10;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vL){
					v[11]++;
					y=11;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vM){
					v[12]++;
					y=12;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vN){
					v[13]++;
					y=13;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vO){
					v[14]++;
					y=14;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
					if(a1==vP){
					v[15]++;
					y=15;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
				if(a1==vQ){
					v[16]++;
					y=16;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}
				if(a1==vR){
					v[17]++;
					y=17;
					acertoudificil[l1-1][c1-1]=1;
					acertoudificil[l2-1][c2-1]=1;
				}	
				if(v[y]>1){
					 
						printf("LETRA {%c} JA ENCONTRADA ANTERIORMENTE!!!\n\n", a1);
						printf("%d/18 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<J; i++) {
	  						for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
	  							else{
							  
							  if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tabdificil[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tabdificil[i][j]);
							 else printf("[%d %d]  ",i+1,j+1);
							 }
							  printf("\n");
						}
						system("pause");

						}
					
					else{
					 printf("ACERTOU!!! (Letra %c)  (+15 Pontos)\n", a1);
					acertos++;
					pontos=pontos+15;
					for(i=0; i<J; i++) {
	  					for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
	  							else{
							  
							  if(i==l1-1&&j==c1-1){
							  	Tabdificil[i][j]=a1;
							  	printf ("   %c   ", Tabdificil[i][j]);
							  }
							else if(i==l2-1&&j==c2-1){
								Tabdificil[i][j]=b1;
								 printf ("   %c   ", Tabdificil[i][j]);
							}
							else printf("[%d %d]  ",i+1,j+1);
					  			}
								  printf("\n");
										}
						printf("%d/18 Pares\n\n",acertos);
						printf("Total de Pontos: %d\n\n",pontos);
						system("pause");
						system("cls");									
						for(i=0; i<J; i++) {
	  						for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							printf("\n");	
						}				
						
		
		
			
	}
}
				 else{
				  printf("ERROU!!! (Letras %c e %c)  (-3 Pontos)\n", a1,b1);
				 pontos=pontos-3;
			printf("%d/18 Pares\n\n",acertos);
			printf("Total de Pontos: %d\n\n",pontos);
						for(i=0; i<J; i++) {
	  						for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
	  							else{
							  
							  if(i==l1-1&&j==c1-1)
	  				  		printf ("   %c   ", Tabdificil[i][j]);
	  						else if(i==l2-1&&j==c2-1)
	  				  		printf ("   %c   ", Tabdificil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							  }
							  printf("\n");
			}
			system("pause");
			system("cls");
						for(i=0; i<J; i++) {
	  						for(j=0; j<J; j++)
	  						if(acertoudificil[i][j]==1)
	  							printf("   %c   ", Tabdificil[i][j]);
							else printf("[%d %d]  ",i+1,j+1);
							printf("\n");	
						}


}
printf("\n\n");
printf("\nVoce ja achou a(s) letra(s):");
if(v[0]>0) printf("A "); if(v[1]>0) printf("B ");if(v[2]>0) printf("C ");if(v[3]>0) printf("D ");
if(v[4]>0) printf("E ");if(v[5]>0) printf("F ");if(v[6]>0) printf("G ");if(v[7]>0) printf("H ");
if(v[8]>0) printf("I ");if(v[9]>0) printf("J ");if(v[10]>0) printf("K ");if(v[11]>0) printf("L ");
if(v[12]>0) printf("M ");if(v[13]>0) printf("N ");if(v[14]>0) printf("O ");if(v[15]>0) printf("P ");
if(v[16]>0) printf("Q ");if(v[17]>0) printf("R ");
printf("\n\n");
printf("\nFaltam a(s) letra(s):");
if(v[0]==0) printf("A ");if(v[1]==0) printf("B ");if(v[2]==0) printf("C ");if(v[3]==0) printf("D ");
if(v[4]==0) printf("E ");if(v[5]==0) printf("F ");if(v[6]==0) printf("G ");if(v[7]==0) printf("H ");
if(v[8]==0) printf("I ");if(v[9]==0) printf("J ");if(v[10]==0) printf("K ");if(v[11]==0) printf("L ");
if(v[12]==0) printf("M ");if(v[13]==0) printf("N ");if(v[14]==0) printf("O ");if(v[15]==0) printf("P ");
if(v[16]==0) printf("Q ");if(v[17]==0) printf("R ");
printf("\n\n");
}
system("pause");
}

int dificil() {
	int tempo=25;
	float **MA;
	MA=alocarmatriz(6,6);
	zeramatriz(MA, 6, 6);
	system("pause");
	system("cls");
	printf("Voce escolheu o jogo Dificil\n\n");
	printf("Quando estiver pronto aperte ENTER para iniciar, BOA SORTE \n\n");
	system("pause");
	system("cls");
	inicia_tabdificil();
	while(tempo!=0){
	printf(" ----  Tabuleiro do Jogo  -----\n\n");
	printf("%d Segundos para decorar\n\n",tempo);
	mostra_tabdificil();
	_sleep(1000);
    system("cls");
    tempo=tempo-1;
}
	esconde_tabdificil();
	jogada_tabdificil();
	system("cls");
	liberarmatriz(MA, 6);
	system("pause");
	system("cls");
	printf("------VOCE VENCEU!!!------\n\n");
	printf("------TOTAL DE PONTOS: %d ------\n\n",pontos);
	printf("Para voltar ao Menu Principal aperte ENTER \n\n");
		
    	
}
int dificuldade(){
int e;
	system("cls");
	printf("-----Escolha uma Dificuldade----- \n");
	printf(" 1 - Facil ( Tabuleiro 4 x 4 , 16 cartas, 8 pares)\n");
	printf(" 2 - Dificil ( Tabuleiro 6 x 6 , 36 cartas, 18 pares)\n");
	printf(" 3 - Retornar ao Menu Principal\n\n\n");
	scanf("%d",&e);
	if(e==1){
		system("cls");
		facil();
		system("pause");
		dificuldade();
		
	}
	if(e==2){
		system("cls");
		dificil();
		system("pause");
		
	}
	if(e==3) return 0;
	
	if(e!=1&&e!=2&&e!=3) {
	     printf("\n\n\nEscolha Incorreta!!!\n\n\n");
	     system("pause");
	     dificuldade();
}
}
void intrucoes(){
	system("cls");
	printf("Nesse jogo voce precisa achar todos os 8 pares( Facil) ou todos os 18 pares (Dificil) para vencer\n\n");
	printf("No modo Facil voce tem 10 segundos para decorar as cartas\n\n");
	printf("No modo Dificil voce tem 25 segundos para decorar as cartas\n\n");
	printf("A cada acerto voce ganha 15 pontos, a cada erro voce perde 3 pontos\n\n");
	printf("Os numeros nas cartas representam a posicao das cartas\n\n");
	printf("O PRIMEIRO numero representa a LINHA e o SEGUNDO representa a  COLUNA\n\n");
	printf("Para escolher uma carta voce deve digitar o numero da LINHA e confirmar\n\n");
	printf("Em seguida voce deve digitar o numero da COLUNA e confirmar\n\n");
	printf("Exemplo: para selecionar a carta [3 2] , primeiro voce deve digitar 3 e apertar ENTER\n\n");
	printf("Em seguida voce deve digitar 2 e apertar ENTER\n\n");
	printf("Para sair desse menu aperte ENTER \n\n");
	system("pause");
	system("cls");
	
	
}
void menuprincipal(){
	int x;
	system("cls");
	printf("------------- JOGO DA MEMORIA -------------\n");
	printf("|	1 - Novo Jogo                     |\n");  
	printf("|	                                  |\n");         
	printf("| 	2 - Carregar Jogo                 | \n");
	printf("|	                                  |\n");
	printf("|	3 - Intrucoes      	          |  \n");
	printf("|	                                  |\n");
	printf("|	4 - Ranking de Pontos             |   \n");
	printf("|	                                  |\n");
	printf("|	5 - Sair                          |    \n");
    printf("-------------------------------------------\n\n");
	
	scanf("%d", &x);
	if(x==1){ dificuldade(); menuprincipal();}
	if(x==2){ printf("Em Breve !!!\n");system("pause"); menuprincipal();}
	if(x==3){ intrucoes(); menuprincipal();}
	if(x==4){ printf("Em Breve !!!\n");system("pause"); menuprincipal();} 
	if(x==5) exit(0);

}

int main(){
	menuprincipal();
	return 0;
}
