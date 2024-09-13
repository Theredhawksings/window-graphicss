#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 30

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void drawRectangle(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int wrappedI = (j - x1 + BOARD_SIZE) % BOARD_SIZE;
            int wrappedJ = (i - y1 + BOARD_SIZE) % BOARD_SIZE;
            if (wrappedI <= (x2 - x1 + BOARD_SIZE) % BOARD_SIZE && wrappedJ <= (y2 - y1 + BOARD_SIZE) % BOARD_SIZE) {
                board[i][j] = '*';
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

int calculateArea(int x1, int y1, int x2, int y2) {
    int width = (x2 - x1 + BOARD_SIZE) % BOARD_SIZE + 1;
    int height = (y2 - y1 + BOARD_SIZE) % BOARD_SIZE + 1;
    return width * height;
}

double calculateAreaRatio(int area) {
    return (double)area / (BOARD_SIZE * BOARD_SIZE) * 100.0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int x1, y1, x2, y2;
    char command;

    resetBoard(board);

    printf("�簢���� ��ǥ�� �Է��ϼ��� (x1, y1) (x2, y2):\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    x1 = (x1 + BOARD_SIZE) % BOARD_SIZE;
    y1 = (y1 + BOARD_SIZE) % BOARD_SIZE;
    x2 = (x2 + BOARD_SIZE) % BOARD_SIZE;
    y2 = (y2 + BOARD_SIZE) % BOARD_SIZE;

    while (1) {
      

        resetBoard(board);
        drawRectangle(board, x1, y1, x2, y2);
        printBoard(board);

        //printf("��ɾ �Է��ϼ��� (x/X: ��/��, y/Y: ��/��, s/S: ���/Ȯ��, I: x�� ���, j/J: y�� Ȯ��/���, m: ���� ���, n: ���� ���� ���, a/A: x�� Ȯ��, y�� ���/�ݴ�, r: ����, q: ����): ");
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }

        switch (command) {
        case 'x': {
            moveX(&x1, &x2, 1);
            break;
        }
        case 'X': {
            moveX(&x1, &x2, -1);
            break;
        }
        case 'y': {
            moveY(&y1, &y2, 1);
            break;
        }
        case 'Y': {
            moveY(&y1, &y2, -1);
            break;
        }
        case 's': {
            if ((x2 - x1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                x2 = (x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }

            if ((y2 - y1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                y2 = (y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }
            break;
        }
        case 'S': {
            x2 = (x2 + 1) % BOARD_SIZE;
            y2 = (y2 + 1) % BOARD_SIZE;
            break;
        }
        case 'I': {
            if ((x2 - x1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                x2 = (x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }
            break;
        }
        case 'j': {
            y2 = (y2 + 1) % BOARD_SIZE;
            break;
        }
        case 'J': {
            if ((y2 - y1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                y2 = (y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }
            break;
        }
        case 'a': {
            x2 = (x2 + 1) % BOARD_SIZE;
            if ((y2 - y1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                y2 = (y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }
            break;
        }
        case 'A': {
            if ((x2 - x1 + BOARD_SIZE) % BOARD_SIZE > 0) {
                x2 = (x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            }
            y2 = (y2 + 1) % BOARD_SIZE;
            break;
        }
        case 'm': {
            int area = calculateArea(x1, y1, x2, y2);
            printf("�簢���� ����: %d\n", area);
            break;
        }
        case 'n': {
            int area = calculateArea(x1, y1, x2, y2);
            double ratio = calculateAreaRatio(area);
            printf("�簢���� ���� ����: %.2f%%\n", ratio);
            break;
        }
        case 'r': {
            printf("���带 �����մϴ�.\n");
            resetBoard(board);
            printf("���ο� ��ǥ�� �Է��ϼ��� (x1, y1) (x2, y2):\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1 = (x1 + BOARD_SIZE) % BOARD_SIZE;
            y1 = (y1 + BOARD_SIZE) % BOARD_SIZE;
            x2 = (x2 + BOARD_SIZE) % BOARD_SIZE;
            y2 = (y2 + BOARD_SIZE) % BOARD_SIZE;
            break;
        }
        }
    }

    return 0;
}
