#include <stdio.h>
#include <stdlib.h>
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
	printf("Digite o 1 numero: \n");
	scanf("%d", &num1);
	printf("Digite o 2 numero: \n");
	scanf("%d", &num2);
	printf(" Maximo divisor comum : %d \n", max(num1,num2));
	system("pause");
	return 0;
	}
