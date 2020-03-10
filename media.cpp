#include <stdio.h>
#include <stdlib.h>
int main () {
	float nota1,nota2,nota3,nota4,media;
	printf("informe as 4 notas: ");
	scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
	media=(nota1+nota2+nota3+nota4)/4;
	printf("media:%.1f",media);
	if(media>=7.0) printf(" Aprovado");
	  else printf(" Reprovado");
	system("pause");
	return 0;
	}
