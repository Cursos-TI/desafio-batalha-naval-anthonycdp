#include <stdio.h>

void printSeparator() {
    printf("\n========================================\n");
}

void displayBoard5x5(int board[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void displayBoard10x10(int board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void noviceLevel() {
    printf("NIVEL NOVATO - Posicionamento Basico\n");
    printSeparator();
    
    int board[5][5] = {0};
    
    // CKDEV-NOTE: Ship 1 positioned horizontally at row 1, columns 1-3
    board[1][1] = 3;
    board[1][2] = 3;
    board[1][3] = 3;
    
    // CKDEV-NOTE: Ship 2 positioned vertically at column 3, rows 2-4
    board[2][3] = 3;
    board[3][3] = 3;
    board[4][3] = 3;
    
    printf("Coordenadas do Navio 1 (Horizontal):\n");
    printf("Posicao [1,1]: ocupada\n");
    printf("Posicao [1,2]: ocupada\n");
    printf("Posicao [1,3]: ocupada\n");
    
    printf("\nCoordenadas do Navio 2 (Vertical):\n");
    printf("Posicao [2,3]: ocupada\n");
    printf("Posicao [3,3]: ocupada\n");
    printf("Posicao [4,3]: ocupada\n");
    
    printf("\nTabuleiro 5x5:\n");
    displayBoard5x5(board);
}

void adventurerLevel() {
    printf("\nNIVEL AVENTUREIRO - Tabuleiro 10x10 com Navios Diagonais\n");
    printSeparator();
    
    int board[10][10] = {0};
    
    // CKDEV-NOTE: Ship 1 horizontal at row 2
    board[2][3] = 3;
    board[2][4] = 3;
    board[2][5] = 3;
    
    // CKDEV-NOTE: Ship 2 vertical at column 7
    board[4][7] = 3;
    board[5][7] = 3;
    board[6][7] = 3;
    
    // CKDEV-NOTE: Ship 3 diagonal from top-left to bottom-right
    board[0][0] = 3;
    board[1][1] = 3;
    board[2][2] = 3;
    
    // CKDEV-NOTE: Ship 4 diagonal from top-right to bottom-left
    board[5][9] = 3;
    board[6][8] = 3;
    board[7][7] = 3;
    
    printf("Navio 1 (Horizontal): posicoes [2,3] [2,4] [2,5]\n");
    printf("Navio 2 (Vertical): posicoes [4,7] [5,7] [6,7]\n");
    printf("Navio 3 (Diagonal): posicoes [0,0] [1,1] [2,2]\n");
    printf("Navio 4 (Diagonal): posicoes [5,9] [6,8] [7,7]\n");
    
    printf("\nTabuleiro 10x10 (0 = vazio, 3 = ocupado):\n");
    displayBoard10x10(board);
}

void masterLevel() {
    printf("\nNIVEL MESTRE - Habilidades Especiais\n");
    printSeparator();
    
    // CKDEV-NOTE: Cone pattern matrix
    printf("Habilidade CONE:\n");
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    
    // CKDEV-NOTE: Octahedron pattern matrix
    printf("\nHabilidade OCTAEDRO:\n");
    int octahedron[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octahedron[i][j]);
        }
        printf("\n");
    }
    
    // CKDEV-NOTE: Cross pattern matrix
    printf("\nHabilidade CRUZ:\n");
    int cross[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cross[i][j]);
        }
        printf("\n");
    }
    
    // CKDEV-NOTE: Demonstrating abilities on 10x10 board
    printf("\nDemonstracao das habilidades em tabuleiro 10x10:\n");
    printSeparator();
    
    int fullBoard[10][10] = {0};
    
    // CKDEV-NOTE: Apply cone at position (2, 3)
    printf("CONE aplicado na posicao [2,3]:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fullBoard[i][j] = 0;
        }
    }
    
    int startRow = 2, startCol = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (startRow + i < 10 && startCol + j - 2 >= 0 && startCol + j - 2 < 10) {
                fullBoard[startRow + i][startCol + j - 2] = cone[i][j];
            }
        }
    }
    displayBoard10x10(fullBoard);
}

int main() {
    printf("=== DESAFIO BATALHA NAVAL - MATECHECK ===\n");
    printSeparator();
    
    noviceLevel();
    printSeparator();
    
    adventurerLevel();
    printSeparator();
    
    masterLevel();
    
    printSeparator();
    printf("\nPrograma finalizado com sucesso!\n");
    printf("\nPressione ENTER para sair...");
    getchar();
    
    return 0;
}
