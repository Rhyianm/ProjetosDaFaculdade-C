#include <stdio.h>
int main(){
	//Os dois primeiros numeros serão informados pelo usuario, entao o contador comeca de 3 e vai ate o 10
	int num1, num2, proximoNum, cont = 3; 
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &num1);
	
	printf("Digite o segundo numero: ");
	scanf("%d", &num2);
	
	printf("Sequencia: \n");
	
	printf("%d\n%d\n", num1, num2);
	while (cont <= 10) {
		
		// Somando os anteriores para gerar o proximo numero
        proximoNum = num1 + num2;  
        
        // Informando o proximo numero
        printf("%d", proximoNum);
        printf("\n");

		// declarando os proximos numeros a ser sinadis
        num1 = num2;
        num2 = proximoNum;

		// Contador para a squencia acabar
        cont++;  
    }
}
