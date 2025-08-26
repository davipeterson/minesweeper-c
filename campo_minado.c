#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 16

typedef struct {
    int mina;
    int revelada;
    int minas_adjacentes;
} Celula;

enum Dificuldade {
    FACIL = 26,
    MEDIO = 38,
    DIFICIL = 51
};

Celula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

void inicializarTabuleiro(enum Dificuldade dificuldade) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = (Celula){0, 0, 0};
        }
    }

    srand((unsigned)time(NULL));
    int num_minas = dificuldade;
    while (num_minas > 0) {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;
        if (!tabuleiro[linha][coluna].mina) {
            tabuleiro[linha][coluna].mina = 1;
            num_minas--;
        }
    }

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (!tabuleiro[i][j].mina) {
                int count = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x, nj = j + y;
                        if (ni >= 0 && ni < TAMANHO_TABULEIRO &&
                            nj >= 0 && nj < TAMANHO_TABULEIRO &&
                            tabuleiro[ni][nj].mina) {
                            count++;
                        }
                    }
                }
                tabuleiro[i][j].minas_adjacentes = count;
            }
        }
    }
}

void exibirTabuleiro() {
    printf("\n  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j].revelada) {
                printf("%c ", tabuleiro[i][j].mina ? '*' : '0' + tabuleiro[i][j].minas_adjacentes);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void revelarCelula(int linha, int coluna) {
    tabuleiro[linha][coluna].revelada = 1;

    if (tabuleiro[linha][coluna].mina) {
        exibirTabuleiro();
        printf("\nVoce perdeu! Revelou uma mina.\n");
        exit(0);
    }

    if (tabuleiro[linha][coluna].minas_adjacentes == 0) {
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int ni = linha + x, nj = coluna + y;
                if (ni >= 0 && ni < TAMANHO_TABULEIRO &&
                    nj >= 0 && nj < TAMANHO_TABULEIRO &&
                    !tabuleiro[ni][nj].revelada) {
                    revelarCelula(ni, nj);
                }
            }
        }
    }
}

int verificarVitoria() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (!tabuleiro[i][j].mina && !tabuleiro[i][j].revelada) {
                return 0;
            }
        }
    }
    exibirTabuleiro();
    printf("\nParabens! Voce venceu!\n");
    return 1;
}

int main() {
    enum Dificuldade dificuldade;
    int opcao;

    printf("Bem-vindo ao Campo Minado!\n");
    printf("Escolha a dificuldade:\n");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: dificuldade = FACIL; break;
        case 2: dificuldade = MEDIO; break;
        case 3: dificuldade = DIFICIL; break;
        default:
            printf("Opcao invalida. Escolha 1, 2 ou 3.\n");
            return 1;
    }

    inicializarTabuleiro(dificuldade);

    int linha, coluna;
    while (!verificarVitoria()) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        exibirTabuleiro();
        printf("\nDigite a linha e a coluna (ex: 3 5): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            printf("Posicao invalida. Tente novamente.\n");
            continue;
        }

        revelarCelula(linha, coluna);
    }

    return 0;
}
