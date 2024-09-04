#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

char ch;

int main() {
	srand(time(NULL));

	int a[5][5];//행렬 1
	int b[5][5];//행렬 2
	int c[5][5];//행렬 3

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = rand() % 2;
			b[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < 2; i++) {

		a[rand() % 4][rand() % 4] = 2;
		b[rand() % 4][rand() % 4] = 2;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	while (1) {
		scanf("%c", &ch);

		if (ch == 'm') {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					
					c[i][j]=
						s


				}
				printf("\n");
			}
		}

		if (ch == 'a') {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", a[i][j]+b[i][j]);
				}
				printf("\n");
			}
		}

		if (ch == 'd') {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", a[i][j] - b[i][j]);
				}
				printf("\n");
			}
		}

	}

	return 0;
}