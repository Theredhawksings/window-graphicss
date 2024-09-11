#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 30

// ���� ��� �Լ�
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// ���� �ʱ�ȭ �Լ�
void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// �簢�� �׸��� �Լ� (wrapping ����)
void drawRectangle(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int wrappedI = (i - y1 + BOARD_SIZE) % BOARD_SIZE;
            int wrappedJ = (j - x1 + BOARD_SIZE) % BOARD_SIZE;
            if (wrappedI <= (y2 - y1 + BOARD_SIZE) % BOARD_SIZE &&
                wrappedJ <= (x2 - x1 + BOARD_SIZE) % BOARD_SIZE) {
                board[i][j] = '*';
            }
        }
    }
}

// X�� �̵� �Լ� (wrapping ����)
void moveX(int* x1, int* x2, int direction) {
    *x1 = (*x1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *x2 = (*x2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

// Y�� �̵� �Լ� (wrapping ����)
void moveY(int* y1, int* y2, int direction) {
    *y1 = (*y1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *y2 = (*y2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int x1, y1, x2, y2;
    char command;

    // ���� �ʱ�ȭ
    resetBoard(board);

    // �ʱ� ��ǥ �Է� �ޱ�
    printf("�簢���� ��ǥ�� �Է��ϼ��� (x1, y1) (x2, y2):\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // �ʱ� ��ǥ�� ���� ũ�⿡ �°� ����
    x1 = (x1 + BOARD_SIZE) % BOARD_SIZE;
    y1 = (y1 + BOARD_SIZE) % BOARD_SIZE;
    x2 = (x2 + BOARD_SIZE) % BOARD_SIZE;
    y2 = (y2 + BOARD_SIZE) % BOARD_SIZE;

    // ���� ���� ����
    while (1) {
        // �簢�� �׸��� �� ���� ���
        resetBoard(board);
        drawRectangle(board, x1, y1, x2, y2);
        printBoard(board);

        // ��ɾ� �Է� �ޱ�
        printf("��ɾ �Է��ϼ��� (x/X: ��/��, y/Y: ��/��, s/S: ���/Ȯ��, q: ����): ");
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }

        // ��ɾ� ó��
        switch (command) {
        case 'x': moveX(&x1, &x2, 1); break;  // ���������� �̵�
        case 'X': moveX(&x1, &x2, -1); break; // �������� �̵�
        case 'y': moveY(&y1, &y2, 1); break;  // �Ʒ��� �̵�
        case 'Y': moveY(&y1, &y2, -1); break; // ���� �̵�
        case 's': // ���
            if ((x2 - x1 + BOARD_SIZE) % BOARD_SIZE > 0) x2 = (x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            if ((y2 - y1 + BOARD_SIZE) % BOARD_SIZE > 0) y2 = (y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            break;
        case 'S': // Ȯ��
            x2 = (x2 + 1) % BOARD_SIZE;
            y2 = (y2 + 1) % BOARD_SIZE;
            break;
        }
    }

    return 0;
}