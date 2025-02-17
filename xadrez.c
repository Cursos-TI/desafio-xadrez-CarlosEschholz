// Desafio de Xadrez - MateCheck
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
#include <stdio.h>

// Função para movimentar peças como Torre e Rainha
void andarCasas(const char *nomePeca, const char *direcao, int *variavel, int qtd) {
    *variavel += qtd;
    printf("A %s andou %d casas para %s\n", nomePeca, qtd, direcao);
}

// Função para movimentação diagonal do Bispo
void andarBispo(int *variavel1, int *variavel2, int limite) {
    for (int i = 1; i <= limite; i++) { // Movimento vertical (subindo)
        for (int j = 1; j <= limite; j++) { // Movimento horizontal (direita)
            if (*variavel1 >= 8 || *variavel2 >= 8) { // Se atingir o limite, parar
                return;
            }

            if (i == j) { // O bispo só se move na diagonal (i == j)
                *variavel1 += 1;
                *variavel2 += 1;
                printf("O bispo andou para (%d, %d)\n", *variavel1, *variavel2);
            }
        }
    }
}

// Função para movimentação do Cavalo
void andarCavalo(int *variavel1, int *variavel2) {
    *variavel1 += 2;
    *variavel2 += 1;
    printf("O cavalo andou %d casas para direita e %d para cima\n", *variavel1, *variavel2);
}

int main() {
    int limite = 7;
    int escolha;

    int posicaoBispoh = 0, posicaoBispov = 0;
    int posicaoCavaloh = 0, posicaoCavalov = 0;
    int posicaoTorre = 0, posicaoRainha = 0;

    while (posicaoBispov <= limite && posicaoRainha <= limite && posicaoTorre <= limite && posicaoCavalov <= limite) {
        printf("Escolha uma peca para jogar:\n");
        printf("1 - Bispo\n2 - Torre\n3 - Rainha\n4 - Cavalo\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                andarBispo(&posicaoBispoh, &posicaoBispov, 5);
                break;
            case 2:
                andarCasas("Torre", "direita", &posicaoTorre, 5);
                break;
            case 3:
                andarCasas("Rainha", "esquerda", &posicaoRainha, 8);
                break;
            case 4:
                andarCavalo(&posicaoCavalov, &posicaoCavaloh);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
        printf("------------------------------------------------\n");
    }

    // Mensagens de fim de jogo
    if (posicaoBispov >= limite) printf("O bispo chegou no limite do tabuleiro\n");
    if (posicaoRainha >= limite) printf("A rainha chegou no limite do tabuleiro\n");
    if (posicaoTorre >= limite) printf("A torre chegou no limite do tabuleiro\n");
    if (posicaoCavalov >= limite) printf("O cavalo chegou no limite do tabuleiro\n");

    return 0;
}
