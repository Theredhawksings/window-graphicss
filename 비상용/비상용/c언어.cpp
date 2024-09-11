#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

void setColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

}

void printBoard(char board[5][5], int revealed[5][5]) {

    printf("  a b c d e\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 5; j++) {
            if (revealed[i][j] != 0) {
                int color = 7;
                if (revealed[i][j] == 1) {
                    color = 12;
                }
                else if (revealed[i][j] == 2) {
                    color = 9;
                }
                setColor(color);
                printf("%c ", board[i][j]);
                setColor(7);
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }

}

void shuffleBoard(char board[5][5]) {
    char characters[] = "@aabbccddeeffgghhiijjkkll";

    int length = 25;
    srand(time(0));

    for (int i = 0; i < length; i++) {
        int rando = rand() % length;
        char temp = characters[i];
        characters[i] = characters[rando];
        characters[rando] = temp;
    }

    int index = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = characters[index];
            index++;
        }
    }

}

void revealAllSameLetters(char board[5][5], int revealed[5][5], char letter, int currentPlayer) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == letter) {
                if (currentPlayer == 1) {
                    revealed[i][j] = 1;
                }
                else if (currentPlayer == 2) {
                    revealed[i][j] = 2;
                }
            }
        }
    }

}

void resetGame(char board[5][5], int revealed[5][5], int* p1attem, int* p2attem, int* p1mat, int* p2mat, bool* joker) {

    shuffleBoard(board);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            revealed[i][j] = 0;
        }
    }

    *p1attem = 0;
    *p2attem = 0;
    *p1mat = 0;
    *p2mat = 0;
    *joker = false;
}

int main() {
    char board[5][5];
    int revealed[5][5] = { 0 };
    int p1attem = 0;
    int p2attem = 0;
    int p1mat = 0;
    int p2mat = 0;
    bool joker = false;

    resetGame(board, revealed, &p1attem, &p2attem, &p1mat, &p2mat, &joker);

    char col1, col2;
    int row1, row2;
    int currentPlayer = 1;

    while (true) {
        system("cls");
        printBoard(board, revealed);

        printf("\n");

        for (int i = 0; i < 5; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < 5; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        printf("\n");


        printf("플레이어 1 시도: %d, 맞춘 횟수: %d\n", p1attem, p1mat);
        printf("플레이어 2 시도: %d, 맞춘 횟수: %d\n", p2attem, p2mat);

        printf("명령어 입력 : ");
        char command[10];
        scanf("%s", command);

        if (command[0] == 'r') {
            if (command[1] == '1' || command[1] == '2') {
                resetGame(board, revealed, &p1attem, &p2attem, &p1mat, &p2mat, &joker);
                currentPlayer = 1;
            }
            continue;
        }

        col1 = command[0];
        row1 = command[1] - '0';

        printf("명령어 입력 : ");
        scanf(" %c%d", &col2, &row2);

        int i1_col = col1 - 'a';
        int i1_row = row1 - 1;
        int i2_col = col2 - 'a';
        int i2_row = row2 - 1;

        if (currentPlayer == 1) {
            p1attem++;
        }
        else {
            p2attem++;
        }

        if (board[i1_row][i1_col] == board[i2_row][i2_col]) {
            if (currentPlayer == 1) {
                p1mat++;
                revealed[i1_row][i1_col] = 1;
                revealed[i2_row][i2_col] = 1;
            }
            else {
                p2mat++;
                revealed[i1_row][i1_col] = 2;
                revealed[i2_row][i2_col] = 2;
            }
        }
        else {
            printf("같지 않습니다.\n");

            if (board[i1_row][i1_col] == '@' && joker == false) {
                revealAllSameLetters(board, revealed, board[i2_row][i2_col], currentPlayer);
                revealed[i1_row][i1_col] = 1;
                joker = true;
            }
            else if (board[i2_row][i2_col] == '@' && joker == false) {
                revealAllSameLetters(board, revealed, board[i1_row][i1_col], currentPlayer);
                revealed[i2_row][i2_col] = 1;
                joker = true;
            }
            else {
                if (revealed[i1_row][i1_col] == 1) {
                    revealed[i1_row][i1_col] = 1;
                }
                else if (revealed[i1_row][i1_col] == 2) {
                    revealed[i1_row][i1_col] = 2;
                }
                else if (revealed[i2_row][i2_col] == 1) {
                    revealed[i2_row][i2_col] = 1;
                }
                else if (revealed[i2_row][i2_col] == 2) {
                    revealed[i2_row][i2_col] = 2;
                }
                else if (revealed[i1_row][i1_col] == 0) {
                    revealed[i1_row][i1_col] = 0;
                }
                else if (revealed[i2_row][i2_col] == 0) {
                    revealed[i2_row][i2_col] = 0;
                }
            }
        }

        bool allRevealed = true;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (revealed[i][j] == 0) {
                    allRevealed = false;
                    break;
                }
            }
            if (!allRevealed) break;
        }

        if (allRevealed) {
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}