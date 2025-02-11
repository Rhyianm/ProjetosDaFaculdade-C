#include <stdio.h>

int main() {

    //Declarando variáveis
    int tamanho, acomp1, acomp2, acomp3;
    
    //Escolhendo tamanho
    printf("Seja Bem Vindo ao Açaí Legal\nTemos três tamanhos disponiveis...\n\n[1] 300ml\n[2] 500ml\n[3] 1000ml\n\nEscolha o tamanho que deseja: ");
    scanf("%d", &tamanho);

    //Escolhendo acompanhamentos
    printf("\nAgora escolha quais acompanhamentos deseja. Nós temos...\n\n[1] Leite Condensado\n[2] Farinha de Tapioca\n[3] Granola\n[4] Ovomaltine\n[5] Sucrilhos\n\n");
    printf("Digite o primeiro acompanhamento: ");
    scanf("%d", &acomp1);
    printf("Digite o segundo acompanhamento: ");
    scanf("%d", &acomp2);
    printf("Digite o terceiro acompanhamento: ");
    scanf("%d", &acomp3);

    //Relembrando tamanho e informando preço
    printf("\nVocê escolheu um açaí de ");
    if (tamanho == 1) {
        printf("300ml. No total, custará R$15,00");
    }
    else if (tamanho == 2) {
        printf("500ml. No total, custará R$18,00");
    }
    else if (tamanho == 3) {
        printf("1000ml. No total, custará R$25,00");
    }
    printf("Aproveite seu açaí :D\n");
    return 0;
}