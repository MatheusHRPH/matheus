#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	float peso, altura, imc;
	printf("informe o peso:");
    scanf("%f", &peso);
    printf("informe a altura:");
    scanf("%f", &altura);
imc=peso/pow(altura,2);
printf("imc:%.1f",peso/pow(altura,2));	
if(imc<20.0) printf(" = Abaixo do Peso");
if(imc>20&&imc<=25) printf(" = Peso Normal");	
if(imc>25&&imc<=30) printf(" = Sobre Peso");
if(imc>30&&imc<=40) printf(" = Obeso");	
if(imc>40) printf(" = Obeso Morbido");	
system("pause");
return 0;
}
