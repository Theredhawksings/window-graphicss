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
        int randomIndex = rand() % length;
        char temp = characters[i];
        characters[i] = characters[randomIndex];
        characters[randomIndex] = temp;
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

void resetGame(char board[5][5], int revealed[5][5], int* player1Attempts, int* player2Attempts, int* player1Matches, int* player2Matches, bool* joker) {
    
    shuffleBoard(board);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            revealed[i][j] = 0;
        }
    }

    *player1Attempts = 0;
    *player2Attempts = 0;
    *player1Matches = 0;
    *player2Matches = 0;
    *joker = false;
}

int main() {
    char board[5][5];
    int revealed[5][5] = { 0 };
    int player1Attempts = 0;
    int player2Attempts = 0;
    int player1Matches = 0;
    int player2Matches = 0;
    bool joker = false;

    resetGame(board, revealed, &player1Attempts, &player2Attempts, &player1Matches, &player2Matches, &joker);

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


        printf("플레이어 1 시도: %d, 맞춘 횟수: %d\n", player1Attempts, player1Matches);
        printf("플레이어 2 시도: %d, 맞춘 횟수: %d\n", player2Attempts, player2Matches);

        printf("명령어 입력 : ");
        char command[10];
        scanf("%s", command);

        if (command[0] == 'r') {
            if (command[1] == '1' || command[1] == '2') {
                resetGame(board, revealed, &player1Attempts, &player2Attempts, &player1Matches, &player2Matches, &joker);
                currentPlayer = 1;
            }
            continue;
        }

        col1 = command[0];
        row1 = command[1] - '0';

        printf("명령어 입력 : ");
        scanf(" %c%d", &col2, &row2);

        int index1_col = col1 - 'a';
        int index1_row = row1 - 1;
        int index2_col = col2 - 'a';
        int index2_row = row2 - 1;

        if (currentPlayer == 1) {
            player1Attempts++;
        }
        else {
            player2Attempts++;
        }

        if (board[index1_row][index1_col] == board[index2_row][index2_col]) {
            if (currentPlayer == 1) {
                player1Matches++;
                revealed[index1_row][index1_col] = 1;
                revealed[index2_row][index2_col] = 1;
            }
            else {
                player2Matches++;
                revealed[index1_row][index1_col] = 2;
                revealed[index2_row][index2_col] = 2;
            }
        }
        else {
            printf("같지 않습니다.\n");

            if (board[index1_row][index1_col] == '@' && joker == false) {
                revealAllSameLetters(board, revealed, board[index2_row][index2_col], currentPlayer);
                revealed[index1_row][index1_col] = 1;
                joker = true;
            }
            else if (board[index2_row][index2_col] == '@' && joker == false) {
                revealAllSameLetters(board, revealed, board[index1_row][index1_col], currentPlayer);
                revealed[index2_row][index2_col] = 1;
                joker = true;
            }
            else {
                if (revealed[index1_row][index1_col] == 1) {
                    revealed[index1_row][index1_col] = 1;
                }
                else if (revealed[index1_row][index1_col] == 2) {
                    revealed[index1_row][index1_col] = 2;
                }
                else if (revealed[index2_row][index2_col] == 1) {
                    revealed[index2_row][index2_col] = 1;
                }
                else if (revealed[index2_row][index2_col] == 2) {
                    revealed[index2_row][index2_col] = 2;
                }
                else if (revealed[index1_row][index1_col] == 0) {
                    revealed[index1_row][index1_col] = 0;
                }
                else if (revealed[index2_row][index2_col] == 0) {
                    revealed[index2_row][index2_col] = 0;
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
