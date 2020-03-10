#include <stdio.h>
#include <stdlib.h>
int main() {
	float a,b,c;
	printf("informe a medida do 1 lado do triangulo: ");
	scanf("%f", &a );
    printf("informe a medida do 2 lado do triangulo: ");
	scanf("%f", &b );
	printf("informe a medida do 3 lado do triangulo: ");
	scanf("%f", &c );
       if(a<b+c&&b<a+c&&c<a+b) printf("eh um triangulo"); // Se a<b+c e b<a+c e c<a+b então é um triangulo
          else printf("nao eh um triangulo");   
			 if(a==b&&b==c) printf(" equilatero"); // Se a=b e b=c então é um triangulo equilatero (3 lados iguais)
             if(a==b&&b!=c||b==c&&c!=a||a==c&&c!=b) printf(" isoceles"); // Se( a=b e b diferente de c) ou (b=c e c diferente de a) ou (a=c e c diferente de b) é um triangulo isoceles (2 lados iguais)
             if(a<b+c&&b<a+c&&c<a+b&&a!=b&&b!=c&&a!=c) printf(" escaleno"); // Se(a<b+c e b<a+c e c<a+b) e ( a diferente de b) e (b difetente de c) e (a diferente de c) é um triangulo escaleno ( Todos os lados diferentes)
 system("pause");     
    return 0;
}
