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
       if(a<b+c&&b<a+c&&c<a+b) printf("eh um triangulo");
          else printf("nao eh um triangulo");   
			 if(a==b&&b==c) printf(" equilatero");
             if(a==b&&b!=c||b==c&&c!=a||a==c&&c!=b) printf(" isoceles");
             if(a<b+c&&b<a+c&&c<a+b&&a!=b&&b!=c&&a!=c) printf(" escaleno");
 system("pause");     
    return 0;
}
