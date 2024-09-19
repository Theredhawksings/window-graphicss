#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BOARD_SIZE 30

#define COLOR_GREEN  10
#define COLOR_YELLOW 14
#define COLOR_RED    12
#define COLOR_WHITE  15

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
            case '#':
                setColor(COLOR_RED);
                break;
            default:
                setColor(COLOR_WHITE);
            }
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    setColor(COLOR_WHITE); 
}

void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void drawRectangle(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, char symbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int wrappedI = (j - x1 + BOARD_SIZE) % BOARD_SIZE;
            int wrappedJ = (i - y1 + BOARD_SIZE) % BOARD_SIZE;
            if (wrappedI <= (x2 - x1 + BOARD_SIZE) % BOARD_SIZE && wrappedJ <= (y2 - y1 + BOARD_SIZE) % BOARD_SIZE) {
                if (board[i][j] != '.' && board[i][j] != symbol) {
                    board[i][j] = '#'; 
                }
                else {
                    board[i][j] = symbol;
                }
            }
        }
    }
}

void moveX(int* x1, int* x2, int direction) {
    *x1 = (*x1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *x2 = (*x2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

void moveY(int* y1, int* y2, int direction) {
    *y1 = (*y1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *y2 = (*y2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

void resizeRectangle(int* x1, int* y1, int* x2, int* y2, int direction) {
    if (direction > 0) { 
        *x2 = (*x2 + 1) % BOARD_SIZE;
        *y2 = (*y2 + 1) % BOARD_SIZE;
    }
    else if (direction < 0) { 
        if ((*x2 - *x1 + BOARD_SIZE) % BOARD_SIZE > 0) {
            *x2 = (*x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
        }
        if ((*y2 - *y1 + BOARD_SIZE) % BOARD_SIZE > 0) {
            *y2 = (*y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int x1_1, y1_1, x2_1, y2_1; 
    int x1_2, y1_2, x2_2, y2_2;
    char command;

    resetBoard(board);

    printf("첫 번째 사각형의 좌표를 입력하세요 (x1, y1) (x2, y2):\n");
    scanf("%d %d %d %d", &x1_1, &y1_1, &x2_1, &y2_1);

    printf("두 번째 사각형의 좌표를 입력하세요 (x1, y1) (x2, y2):\n");
    scanf("%d %d %d %d", &x1_2, &y1_2, &x2_2, &y2_2);

    x1_1 = (x1_1 + BOARD_SIZE) % BOARD_SIZE;
    y1_1 = (y1_1 + BOARD_SIZE) % BOARD_SIZE;
    x2_1 = (x2_1 + BOARD_SIZE) % BOARD_SIZE;
    y2_1 = (y2_1 + BOARD_SIZE) % BOARD_SIZE;

    x1_2 = (x1_2 + BOARD_SIZE) % BOARD_SIZE;
    y1_2 = (y1_2 + BOARD_SIZE) % BOARD_SIZE;
    x2_2 = (x2_2 + BOARD_SIZE) % BOARD_SIZE;
    y2_2 = (y2_2 + BOARD_SIZE) % BOARD_SIZE;

    while (1) {
        resetBoard(board);
        drawRectangle(board, x1_1, y1_1, x2_1, y2_1, '*');
        drawRectangle(board, x1_2, y1_2, x2_2, y2_2, '+');
        printBoard(board);

        printf("명령어를 입력하세요: ");
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }

        switch (command) {
        case 'x':
            moveX(&x1_1, &x2_1, 1);
            break;
        case 'X':
            moveX(&x1_1, &x2_1, -1);
            break;
        case 'y':
            moveY(&y1_1, &y2_1, 1);
            break;
        case 'Y':
            moveY(&y1_1, &y2_1, -1);
            break;
        case 's':
            resizeRectangle(&x1_1, &y1_1, &x2_1, &y2_1, -1);
            break;
        case 'S':
            resizeRectangle(&x1_1, &y1_1, &x2_1, &y2_1, 1);
            break;
        case 'w':
            moveX(&x1_2, &x2_2, 1);
            break;
        case 'W':
            moveX(&x1_2, &x2_2, -1);
            break;
        case 'a':
            moveY(&y1_2, &y2_2, 1);
            break;
        case 'A':
            moveY(&y1_2, &y2_2, -1);
            break;
        case 'd':
            resizeRectangle(&x1_2, &y1_2, &x2_2, &y2_2, -1);
            break;
        case 'D':
            resizeRectangle(&x1_2, &y1_2, &x2_2, &y2_2, 1);
            break;
        case 'r':
            printf("보드를 리셋합니다.\n");
            resetBoard(board);
            printf("첫 번째 사각형의 새로운 좌표를 입력하세요 (x1, y1) (x2, y2):\n");
            scanf("%d %d %d %d", &x1_1, &y1_1, &x2_1, &y2_1);
            printf("두 번째 사각형의 새로운 좌표를 입력하세요 (x1, y1) (x2, y2):\n");
            scanf("%d %d %d %d", &x1_2, &y1_2, &x2_2, &y2_2);
            x1_1 = (x1_1 + BOARD_SIZE) % BOARD_SIZE;
            y1_1 = (y1_1 + BOARD_SIZE) % BOARD_SIZE;
            x2_1 = (x2_1 + BOARD_SIZE) % BOARD_SIZE;
            y2_1 = (y2_1 + BOARD_SIZE) % BOARD_SIZE;
            x1_2 = (x1_2 + BOARD_SIZE) % BOARD_SIZE;
            y1_2 = (y1_2 + BOARD_SIZE) % BOARD_SIZE;
            x2_2 = (x2_2 + BOARD_SIZE) % BOARD_SIZE;
            y2_2 = (y2_2 + BOARD_SIZE) % BOARD_SIZE;
            break;
        }
    }

    return 0;
}