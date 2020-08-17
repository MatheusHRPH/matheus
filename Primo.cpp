#include <stdlib.h>
#include <stdio.h>

int primo ( int N) {
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
	int main (){
	int num;
	printf("Digite um numero: \n");
	scanf("%d", &num);
	printf("O resultado foi : %d\n", primo(num));
	printf("1 = Primo (Divide apenas por 1 e por ele mesmo[%d] )\n", num);
	printf("0 = Nao Primo  \n");
	system("pause");
	return 0;
	}
