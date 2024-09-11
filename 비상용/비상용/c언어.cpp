#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 30

// 보드 출력 함수
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// 보드 초기화 함수
void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// 사각형 그리기 함수 (wrapping 지원)
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

// X축 이동 함수 (wrapping 지원)
void moveX(int* x1, int* x2, int direction) {
    *x1 = (*x1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *x2 = (*x2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

// Y축 이동 함수 (wrapping 지원)
void moveY(int* y1, int* y2, int direction) {
    *y1 = (*y1 + direction + BOARD_SIZE) % BOARD_SIZE;
    *y2 = (*y2 + direction + BOARD_SIZE) % BOARD_SIZE;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int x1, y1, x2, y2;
    char command;

    // 보드 초기화
    resetBoard(board);

    // 초기 좌표 입력 받기
    printf("사각형의 좌표를 입력하세요 (x1, y1) (x2, y2):\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // 초기 좌표를 보드 크기에 맞게 조정
    x1 = (x1 + BOARD_SIZE) % BOARD_SIZE;
    y1 = (y1 + BOARD_SIZE) % BOARD_SIZE;
    x2 = (x2 + BOARD_SIZE) % BOARD_SIZE;
    y2 = (y2 + BOARD_SIZE) % BOARD_SIZE;

    // 메인 게임 루프
    while (1) {
        // 사각형 그리기 및 보드 출력
        resetBoard(board);
        drawRectangle(board, x1, y1, x2, y2);
        printBoard(board);

        // 명령어 입력 받기
        printf("명령어를 입력하세요 (x/X: 우/좌, y/Y: 하/상, s/S: 축소/확대, q: 종료): ");
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }

        // 명령어 처리
        switch (command) {
        case 'x': moveX(&x1, &x2, 1); break;  // 오른쪽으로 이동
        case 'X': moveX(&x1, &x2, -1); break; // 왼쪽으로 이동
        case 'y': moveY(&y1, &y2, 1); break;  // 아래로 이동
        case 'Y': moveY(&y1, &y2, -1); break; // 위로 이동
        case 's': // 축소
            if ((x2 - x1 + BOARD_SIZE) % BOARD_SIZE > 0) x2 = (x2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            if ((y2 - y1 + BOARD_SIZE) % BOARD_SIZE > 0) y2 = (y2 - 1 + BOARD_SIZE) % BOARD_SIZE;
            break;
        case 'S': // 확대
            x2 = (x2 + 1) % BOARD_SIZE;
            y2 = (y2 + 1) % BOARD_SIZE;
            break;
        }
    }

    return 0;
}