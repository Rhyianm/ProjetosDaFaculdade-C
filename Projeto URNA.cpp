#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    // Nomes, números e idades dos candidatos
    char nome1[] = "George", nome2[] = "Paulo", nome3[] = "Nickolas", nome4[] = "Ana";
    int numero1 = 23, numero2 = 47, numero3 = 98, numero4 = 55;
    int idade1 = 60, idade2 = 55, idade3 = 40, idade4 = 45;

    int votos1 = 0, votos2 = 0, votos3 = 0, votos4 = 0;
    int brancos = 0, nulos = 0;
    int voto, populacao, confirmarVoto;
    char senhaCorreta[] = "17098"; // Senha definida
    char senha[10];                // Para entrada da senha

    printf("Quantas pessoas há em sua cidade?\n- ");
    scanf("%d", &populacao);
    printf("\n");

    int continuarVotacao = 1;
    int totalVotos = 0;

    // Primeiro turno
    while (continuarVotacao)
    {

        printf("Digite o número do seu candidato: ");
        scanf("%d", &voto);

        // Confirmação do candidato escolhido
        /*
            Criei esse sistema de confirmar voto pois, na urna de verdade, quando
            um eleitor digita o numero de um candidato, se a numeração estiver correta,
            aparece a foto do candidato na parte direita da tela, antes do eleitor confirmar voto.
            Aqui é para ser quase a mesma coisa, antes do eleitor confirmar o voto, ele vai ser
            avisado sobre quem ele está votando.
        */
        switch (voto)
        {
        case 23:
            printf("%s? (1 - Sim, 0 - Não): ", nome1);
            break;
        case 47:
            printf("%s? (1 - Sim, 0 - Não): ", nome2);
            break;
        case 98:
            printf("%s? (1 - Sim, 0 - Não): ", nome3);
            break;
        case 55:
            printf("%s? (1 - Sim, 0 - Não): ", nome4);
            break;
        default:
            printf("Nulo? (1 - Sim, 0 - Não): ");
            break;
        }
        scanf("%d", &confirmarVoto);

        if (confirmarVoto == 1)
        {
            switch (voto)
            {
            case 23:
                votos1++;
                break;
            case 47:
                votos2++;
                break;
            case 98:
                votos3++;
                break;
            case 55:
                votos4++;
                break;
            case 0:
                brancos++;
                break;
            default:
                nulos++;
                break;
            }
            totalVotos++;
        }
        else
        {
            printf("Voto cancelado. Tente novamente.\n");
            continue; // Retorna ao início do loop inserir o numero novamente
        }

        // Verificação para continuar ou encerrar a votação (funcionarios)
        printf("\nContinuar votação? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuarVotacao);
        printf("\n");

        // Se a opção for 0, pede a senha para encerrar (apenas funcionarios saberão a senha)
        if (continuarVotacao == 0)
        {
            printf("Digite a senha para encerrar a votação: ");
            scanf("%s", senha);

            if (strcmp(senha, senhaCorreta) != 0)
            {
                printf("Senha incorreta. A votação continuará.\n");
                continuarVotacao = 1; // Continua a votação
            }
        }
    }

    // Exibir resultados do primeiro turno
    printf("\nResultados do Primeiro Turno:\n");
    printf("%s: %d votos (%.2f%%)\n", nome1, votos1, (votos1 * 100.0) / totalVotos);
    printf("%s: %d votos (%.2f%%)\n", nome2, votos2, (votos2 * 100.0) / totalVotos);
    printf("%s: %d votos (%.2f%%)\n", nome3, votos3, (votos3 * 100.0) / totalVotos);
    printf("%s: %d votos (%.2f%%)\n", nome4, votos4, (votos4 * 100.0) / totalVotos);
    printf("Brancos: %d votos (%.2f%%)\n", brancos, (brancos * 100.0) / totalVotos);
    printf("Nulos: %d votos (%.2f%%)\n", nulos, (nulos * 100.0) / totalVotos);

    // Determinar os dois candidatos mais votados
    int primeiro, segundo, votosPrimeiro, votosSegundo;

    if (votos1 >= votos2 && votos1 >= votos3 && votos1 >= votos4)
    {
        primeiro = numero1;
        votosPrimeiro = votos1;
        if (votos2 >= votos3 && votos2 >= votos4)
        {
            segundo = numero2;
            votosSegundo = votos2;
        }
        else if (votos3 >= votos2 && votos3 >= votos4)
        {
            segundo = numero3;
            votosSegundo = votos3;
        }
        else
        {
            segundo = numero4;
            votosSegundo = votos4;
        }
    }
    else if (votos2 >= votos1 && votos2 >= votos3 && votos2 >= votos4)
    {
        primeiro = numero2;
        votosPrimeiro = votos2;
        if (votos1 >= votos3 && votos1 >= votos4)
        {
            segundo = numero1;
            votosSegundo = votos1;
        }
        else if (votos3 >= votos1 && votos3 >= votos4)
        {
            segundo = numero3;
            votosSegundo = votos3;
        }
        else
        {
            segundo = numero4;
            votosSegundo = votos4;
        }
    }
    else if (votos3 >= votos1 && votos3 >= votos2 && votos3 >= votos4)
    {
        primeiro = numero3;
        votosPrimeiro = votos3;
        if (votos1 >= votos2 && votos1 >= votos4)
        {
            segundo = numero1;
            votosSegundo = votos1;
        }
        else if (votos2 >= votos1 && votos2 >= votos4)
        {
            segundo = numero2;
            votosSegundo = votos2;
        }
        else
        {
            segundo = numero4;
            votosSegundo = votos4;
        }
    }
    else
    {
        primeiro = numero4;
        votosPrimeiro = votos4;
        if (votos1 >= votos2 && votos1 >= votos3)
        {
            segundo = numero1;
            votosSegundo = votos1;
        }
        else if (votos2 >= votos1 && votos2 >= votos3)
        {
            segundo = numero2;
            votosSegundo = votos2;
        }
        else
        {
            segundo = numero3;
            votosSegundo = votos3;
        }
    }

    if (populacao >= 200000)
    {
        printf("\nHaverá segundo turno entre os candidatos %d e %d.\n", primeiro, segundo);

        votosPrimeiro = votosSegundo = 0; // Zerar votos para o segundo turno
        totalVotos = 0;
        continuarVotacao = 1;

        printf("\nSegundo Turno:\n");
        while (continuarVotacao)
        {

            printf("\nDigite o número do seu candidato: ");
            scanf("%d", &voto);

            // Confirmação do candidato no segundo turno
            if (voto == primeiro)
            {
                printf("%d? (1 - Sim, 0 - Não): ", primeiro);
            }
            else if (voto == segundo)
            {
                printf("%d? (1 - Sim, 0 - Não): ", segundo);
            }
            else
            {
                printf("Você escolheu um voto nulo. Deseja confirmar? (1 - Sim, 0 - Não): ");
            }
            scanf("%d", &confirmarVoto);

            if (confirmarVoto == 1)
            {
                if (voto == primeiro)
                    votosPrimeiro++;
                else if (voto == segundo)
                    votosSegundo++;
                else
                    nulos++;

                totalVotos++;
            }
            else
            {
                printf("Voto cancelado. Tente novamente.\n");
                continue; // Retorna ao início do loop para novo voto
            }

            // Verificação para continuar ou encerrar a votação no segundo turno
            printf("\nContinuar votação? (1 - Sim, 0 - Não): ");
            scanf("%d", &continuarVotacao);

            if (continuarVotacao == 0)
            {
                printf("Digite a senha para encerrar a votação: ");
                scanf("%s", senha);

                if (strcmp(senha, senhaCorreta) != 0)
                {
                    printf("Senha incorreta. A votação continuará.\n");
                    continuarVotacao = 1;
                }
            }
        }

        if (votosPrimeiro > votosSegundo)
        {
            printf("\nVencedor do Segundo Turno: %d\n", primeiro);
        }
        else
        {
            printf("\nVencedor do Segundo Turno: %d\n", segundo);
        }
    }
    else
    {
        printf("\nNão haverá segundo turno.\n");
    }

    return 0;
}

/*
    apenas para deixar avisado os numeros pro professor

    23 - George
    47 - Paulo
    98 - Nickloas
    55 - Ana

    a senha para encerrar votação é 17098
*/

// Feito por: Carlos Henrique e Ryan Mendes