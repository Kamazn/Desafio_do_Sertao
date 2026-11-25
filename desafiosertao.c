#include <stdio.h>
#include <stdlib.h>

struct Resultado {
    int acertos, pontos;
};
struct Jogador {
    char nome[30];
    struct Resultado resultado;
};

struct Jogador jogador;
char perguntas[5][100] = {
    "Qual estado tem Recife como capital?",
    "Qual destes alimentos e feito com milho?",
    "Quem ficou conhecido como o Rei do Cangaco?",
    "Qual destes biomas e muito presente no sertao nordestino?",
    "Qual festa e conhecida pelas quadrilhas e fogueiras?"
};
char alternativa1[5][40] = {"Paraiba", "Pamonha", "Dom Pedro", "Amazonia", "Sao Joao"};
char alternativa2[5][40] = {"Pernambuco", "Sushi", "Tiradentes", "Caatinga", "Natal"};
char alternativa3[5][40] = {"Bahia", "Macarrao", "Lampiao", "Pantanal", "Carnaval"};
int respostas[5] = {2, 1, 3, 2, 1};
int opcao, resposta, acerto;
int iniciarPartida();
int perguntar(int numero);
int mostrarHistoria();
int salvarResultado();

int main() {
    system("cls");
    do {
        printf("=== DESAFIO DO SERTAO ===\n");
        printf("1 - Jogar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            getchar();
            printf("Seu nome: ");
            fgets(jogador.nome, 30, stdin);
            iniciarPartida();
            system("cls");
        } else if (opcao != 0) {
            system("cls");
            printf("Opcao invalida.\n\n");
        }
    } while (opcao != 0);
    return 0;
}

int iniciarPartida() {
    jogador.resultado.acertos = 0;
    jogador.resultado.pontos = 0;
    mostrarHistoria();
    system("pause");

    for (int i = 0; i < 5; i = i + 1) {
        acerto = perguntar(i);
        if (acerto == 1) {
            jogador.resultado.acertos = jogador.resultado.acertos + 1;
            jogador.resultado.pontos = jogador.resultado.pontos + 10;
            }
    }

    system("cls");
    printf("=== RESULTADO DA PARTIDA ===\n");
    printf("Jogador: %s", jogador.nome);
    printf("Acertos: %d de 5\n", jogador.resultado.acertos);
    printf("Pontuacao final: %d\n", jogador.resultado.pontos);
    salvarResultado();
    system("pause");
    return jogador.resultado.pontos;
}

int perguntar(int numero) {
    do {
        system("cls");
        printf("=== PERGUNTA %d ===\n", numero + 1);
        printf("%s\n", perguntas[numero]);
        printf("1 - %s\n", alternativa1[numero]);
        printf("2 - %s\n", alternativa2[numero]);
        printf("3 - %s\n", alternativa3[numero]);
        printf("Resposta (Digite apenas o numero): ");
        scanf("%d", &resposta);

        if (resposta < 1 || resposta > 3) {
            printf("Opcao invalida. Escolha de 1 a 3.\n");
            system("pause");
        }
    } while (resposta < 1 || resposta > 3);

    if (resposta == respostas[numero]) {
        printf("Voce acertou!\n");
        system("pause");
        return 1;
    } else {
        printf("Voce errou! Tente novamente na proxima.\n");
        system("pause");
        return 0;
    }
}

int mostrarHistoria() {
    FILE *arquivo = fopen("historia.txt", "r");
    char linha[200];
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir historia.txt.\n");
        return 0;
    }

    printf("\n=== COMO JOGAR ===\n");
    while (fgets(linha, 200, arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
    return 0;
}

int salvarResultado() {
    FILE *arquivo = fopen("ranking.txt", "a");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir ranking.txt.\n");
        return 0;
    }

    fprintf(arquivo, "=== RESULTADO DA PARTIDA ===\n");
    fprintf(arquivo, "Jogador: %s", jogador.nome);
    fprintf(arquivo, "Acertos: %d\n", jogador.resultado.acertos);
    fprintf(arquivo, "Pontos: %d\n\n", jogador.resultado.pontos);
    
    fclose(arquivo);
    printf("Resultado salvo em ranking.txt.\n");
    return 0;
}
