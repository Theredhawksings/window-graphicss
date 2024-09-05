#define MAX_LEN 100
#define MAX_LINES 100
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <cstring>

enum ColorType { WHITE = 15, GRAY = 8, BLUE = 9, GREEN = 10 } COLOR;
char ch;

bool ccc = true;
bool ddd = true;
bool eee = true;
bool fff = true;
bool ggg = true;

int rrr = 0;
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
        printf("\n");

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

        if (ch == 'e') {
            if (eee == true) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        if (j % 3 == 0 && j > 0) {
                            printf("@@");
                        }
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }



            }
            else {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }
            eee = !eee;
        }

        if (ch == 'f') {
       
            if (fff) {
                for (int i = 0; i < lineIndex; i++) {
                    int len = strlen(data[i]);
                    int wordStart = 0;

                    for (int j = 0; j <= len; j++) {
                        if (data[i][j] == ' ') {
                            for (int k = j - 1; k >= wordStart; k--) {
                                printf("%c", data[i][k]);
                            }
                            if (data[i][j] == ' ') {
                                printf(" ");
                            }
                            wordStart = j + 1;
                        }
                    }
                    printf("\n");
                }
            }

            else if (!fff) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }

            fff = !fff;
        }

        if (ch == 'g') {
            if (ggg) {
                char ch1, ch2;

                scanf(" %c", &ch1); 
                scanf(" %c", &ch2);  

                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        if (data[i][j] == ch1) {
                            printf("%c", ch2);
                        }
                        else printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }

            else if (!ggg) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }

            ggg = !ggg;
        }

        if (ch == 'h') {
            for (int i = 0; i < lineIndex; i++) {
                int count = 0;
                for (int j = 0; data[i][j] != '\0'; j++) {
                    if (data[i][j] == ' ') {
                        count++;
                    }
                    printf("%c", data[i][j]);
                }
                printf("  %d \n",count+1);
            }
        }

        if (ch == 'r') {
            int a[11] = {};

            for (int i = 0; i < lineIndex; i++) {
                int count = 0;
                for (int j = 0; data[i][j] != '\0'; j++) {
                    if (data[i][j] == ' ') {
                        count++;
                    }
                }
                a[i] = count;
            }

            if (rrr == 0) {
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < lineIndex; j++) {
                        if (a[j] == i) {
                            for (int k = 0; data[j][k] != '\0'; k++) {
                                printf("%c", data[j][k]);
                            }
                            printf("\n");
                        }
                    }
                }
            }

            if (rrr == 1) {
                for (int i = 100; i >=0 ; i--) {
                    for (int j = 0; j < lineIndex; j++) {
                        if (a[j] == i) {
                            for (int k = 0; data[j][k] != '\0'; k++) {
                                printf("%c", data[j][k]);
                            }
                            printf("\n");
                        }
                    }
                }
            }

            if (rrr == 2) {
                for (int i = 0; i < lineIndex; i++) {
                    for (int j = 0; data[i][j] != '\0'; j++) {
                        printf("%c", data[i][j]);
                    }
                    printf("\n");
                }
            }

            rrr++;

            if (rrr == 3) {
                rrr = 0;
            }
        }

        if (ch == 's') {
            char targetWord[MAX_LEN];
            int count = 0;  
            int len = 0;

            printf("찾을 단어를 입력하세요: ");
            scanf("%s", targetWord);

            len = strlen(targetWord);

            for (int i = 0; i < lineIndex; i++) {
                for (int j = 0; data[i][j] != '\0'; j++) {

                    if (_strnicmp(&data[i][j], targetWord, len) == 0) {

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                        for (int k = 0; k < len; k++) {
                            printf("%c", data[i][j + k]);
                        }

                        count++;
                        j += len - 1; 
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        printf("%c", data[i][j]);
                    }
                }
                printf("\n");
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            printf("%d번.\n", count);
        }

    }



    return 0;
}
