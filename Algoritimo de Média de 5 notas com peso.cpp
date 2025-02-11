#include <stdio.h>

int main() {
    float nota, soma = 0, media;
    int peso, i = 1;

    while (i <= 5) {
        printf("Digite a nota %d: ", i);
        scanf("%f", &nota);

        if (nota < 0 || nota > 10) {
            printf("Nota invalida!\n");
        } else {

            if (i == 1) peso = 2;
            else if (i == 2) peso = 4;
            else if (i == 3) peso = 5;
            else if (i == 4) peso = 1;
            else if (i == 5) peso = 1;

            printf("Nota %d: %.2f, Peso: %d, Sua nota multiplicada pelo seu respectivo peso e: %.2f\n\n", i, nota, peso, nota * peso);

            soma += nota * peso;
            i++;
        }
    }

    printf("\nSoma das notas multiplicadas pelos seus respectivos pesos: %.2f\n", soma);
	printf("As notas somadas serão divididas por 13\n\n");
	
    media = soma / (2 + 4 + 5 + 1 + 1);

    printf("A media ponderada das notas e: %.2f\n", media);	

}

