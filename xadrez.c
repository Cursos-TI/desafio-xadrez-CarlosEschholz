 // Desafio de Xadrez - MateCheck
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
#include <stdio.h>

int main() {
    
    int limite = 7;
    int escolha;
    //como o bispo se move na diagonal preciso das duas dimensões
    int posicaoBispoh = 0; 
    int posicaoBispov = 0;
    //o cavalo anda em formato de L
    int posicaoCavaloh = 0;
    int posicaoCavalov = 0;
    //outras peças
    int posicaoTorre = 0; 
    int posicaoRainha = 0;

    while ( posicaoBispov <= limite && posicaoRainha <= limite && posicaoTorre <= limite && posicaoCavaloh <= limite)
    {
         //entrada do usuario
        printf("Escolha uma peca para jogar:\n");
        printf("1 - Bispo\n2 - Torre\n3 - Rainha\n4 - Cavalo\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            posicaoBispoh += 5;
            posicaoBispov += 5;
            printf("O bispo andou %d casas para direita e %d casas para cima\n",posicaoBispoh,posicaoBispov);
            printf("------------------------------------------------\n");
            break;
        case 2:
            posicaoTorre += 5;
            printf("A torre andou %d casas para direita\n",posicaoTorre);
            printf("------------------------------------------------\n");
            break;
        case 3:
            posicaoRainha += 8;
            printf("A rainha andou %d casas para esquerda\n",posicaoRainha);
            printf("------------------------------------------------\n");
            break;
        case 4:
            int jogadas;
            printf("quantas jogadas quer fazer com o cavalo: \n");
            scanf("%d",&jogadas);
            //executando as jogadas
            for(int x = 1; x <= jogadas; x += 1){
                int movimentos = 0;
                do {
                    posicaoCavaloh += 2;
                    posicaoCavalov += 1;
                    printf("O cavalo andou %d para esquerda e %d para baixo\n",posicaoCavaloh,posicaoCavalov);
                    printf("------------------------------------------------\n");
                    movimentos += 1;
                } while (movimentos < 1);
            }
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    if(posicaoBispov >= limite){
        printf("O bispo chegou no limite do tabuleiro\n");
    }
    if(posicaoRainha >= limite){
        printf("A rainha chegou no limite do tabuleiro\n");
    }
    if(posicaoTorre >= limite){
        printf("A torre chegou no limite do tabuleiro\n");
    }
    if(posicaoCavaloh >= limite){
        printf("O cavalo chegou no limite do tabuleiro\n");
    }

    return 0;

}
