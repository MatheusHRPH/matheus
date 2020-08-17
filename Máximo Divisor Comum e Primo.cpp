#include <stdio.h>
#include <stdlib.h>
int primo1 ( int N) {
	int  resultado;
	resultado=0;
	if(N == 2 || N == 3 || N == 5 || N == 7 ) resultado =1;
	 else
	 	if (N==9) resultado=0;
	  else{
	 	if(N % 2  == 0) resultado=0;
		 else{
		 	if(N%3 ==0) resultado=0;
		 	 else{
		 	 	if(N%5==0) resultado=0;
		 	 	 else{
		 	 	 	if(N%7==0) resultado=0;
		 	 	 	 else{
		 	 	 	 	if(N%9==0) resultado=0;
		 	 	 	 	 else{
		 	 	 	 	 	resultado=1; 
		 	 	 	 	 	
							 }
						}
				   }
			  }
		}
}
return resultado;
}
int primo2 ( int N) {
	int  resultado;
	resultado=0;
	if(N == 2 || N == 3 || N == 5 || N == 7 ) resultado =1;
	 else
	 	if (N==9) resultado=0;
	 else{
	 	if(N % 2  == 0) resultado=0;
		 else{
		 	if(N%3 ==0) resultado=0;
		 	 else{
		 	 	if(N%5==0) resultado=0;
		 	 	 else{
		 	 	 	if(N%7==0) resultado=0;
		 	 	 	 else{
		 	 	 	 	if(N%9==0) resultado=0;
		 	 	 	 	 else{
		 	 	 	 	 	resultado=1; 
		 	 	 	 	 	
							 }
						}
				   }
			  }
		}
}
return resultado;
}
int max( int num1, int num2){
	int resultado, divisor, maior, contagem;
	resultado=0;
	divisor=1;
	contagem=0;
	if (num1 >= num2){
	 maior=num1;
}
	 else (num1 < num2);{
	 	maior=num2;
	 }
	 while(contagem <= maior){
		if(num1%divisor==0 && num2%divisor==0 && divisor>resultado){
	     resultado = divisor;
		 divisor = divisor+1;
		 contagem= contagem +1;
		}
	else{
		  resultado=resultado;
		 divisor= divisor+1;
		 contagem= contagem +1;
	}
}
return resultado;
	}
int main () {
	int num1, num2;
	printf("Digite o 1 numero: \n\n");
	scanf("%d", &num1);
	printf("Digite o 2 numero: \n\n");
	scanf("%d", &num2);
	printf(" Maximo divisor comum : %d \n\n", max(num1,num2));
	printf("O resultado do primeiro numero [%d] foi : %d [0 = Nao Primo 1 = Primo]\n\n", num1, primo1(num1));
	printf("O resultado do segundo numero [%d] foi : %d [0 = Nao Primo 1 = Primo]\n\n", num2, primo2(num2));
	//printf("1 = Primo (Divide apenas por 1 e por ele mesmo )\n");
	//printf("0 = Nao Primo  \n");
	system("pause");
	return 0;
	}
