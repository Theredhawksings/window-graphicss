#define MAX_LEN 100
#define MAX_LINES 100
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

enum ColorType { WHITE = 15, GRAY = 8, BLUE = 9, GREEN = 10 } COLOR;
char ch;

bool ccc = true;
bool ddd = true;

int main() {
    char data[MAX_LINES][MAX_LEN];  // 2차원 배열 선언
    int lineIndex = 0;

    FILE* fs = fopen("data.txt", "r");

    int ch;
    int colIndex = 0;

    while ((ch = fgetc(fs)) != EOF && lineIndex < MAX_LINES) {
        if (ch == '\n') {
            data[lineIndex][colIndex] = '\0';
            lineIndex++;
            colIndex = 0;
        }
        else if (colIndex < MAX_LEN - 1) {
            data[lineIndex][colIndex] = ch;
            colIndex++;
        }
    }

    if (colIndex > 0 && lineIndex < MAX_LINES) {
        data[lineIndex][colIndex] = '\0';
        lineIndex++;
    }

    fclose(fs);

    for (int i = 0; i < lineIndex; i++) {
        for (int j = 0; data[i][j] != '\0'; j++) {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }

    while (1) {
        ch = getchar();

        if (ch == 'c') {
            if (ccc == true) {

                int upperCaseWordCount = 0;
                int inWord = 0;
                int colorizeWord = 0;

                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {

                        if (!inWord && data[i][j] >= 'A' && data[i][j] <= 'Z' && (j == 0 || data[i][j - 1] == ' ')) {
                            upperCaseWordCount++;
                            colorizeWord = 1;
                            inWord = 1;
                        }
                        else if (data[i][j] == ' ') {
                            inWord = 0;
                            colorizeWord = 0;
                        }

                        if (colorizeWord) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        }

                        printf("%c", data[i][j]);
                    }
                    printf("\n"); // Print newline after each line
                    inWord = 0; // 새 줄에서는 단어를 벗어난 상태로 초기화
                    colorizeWord = 0; // 새 줄에서는 색칠 상태 초기화
                }
                printf("\n%d\n", upperCaseWordCount);
            }
            if (ccc == false) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }
            ccc = !ccc;
        }

        if (ch == 'd') {
            if (ddd == true) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = strlen(data[i]) - 1; j >= 0; j--) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }
            else if (ddd == false) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }
            ddd = !ddd;
        }

    }

    return 0;
}
