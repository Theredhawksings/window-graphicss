#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

char ch;
int count = 1;

int main() {
	srand(time(NULL));

	int a[5][5];//青纺 1
	int b[5][5];//青纺 2
	int c[5][5];//青纺 3
	int d[5][5];//青纺 3

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
					c[i][j] = 0;

					for (int k = 0; k < 4; k++) {
						c[i][j] += a[i][k] * b[k][j];
					}
				}
			}

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", c[i][j]);
				}
				printf("\n");
			}

		}

		if (ch == 'a') {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", a[i][j] + b[i][j]);
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

		if (ch == 'r') {
			int s1 = a[0][0] * (a[1][1] * (a[2][2] * a[3][3] - a[3][2] * a[2][3]) - a[1][2] * (a[2][1] * a[3][3] - a[2][3] * a[3][1]) + a[1][3] * (a[2][1] * a[3][2] - a[2][2] * a[3][1]));
			int s2 = a[0][1] * (a[1][0] * (a[2][2] * a[3][3] - a[3][2] * a[2][3]) - a[1][2] * (a[2][0] * a[3][3] - a[2][3] * a[3][0]) + a[1][3] * (a[2][0] * a[3][2] - a[2][2] * a[3][0]));
			int s3 = a[0][2] * (a[1][0] * (a[2][1] * a[3][3] - a[3][1] * a[2][3]) - a[1][1] * (a[2][0] * a[3][3] - a[2][3] * a[3][0]) + a[1][3] * (a[2][0] * a[3][1] - a[2][1] * a[3][0]));
			int s4 = a[0][3] * (a[1][0] * (a[2][1] * a[3][2] - a[3][1] * a[2][2]) - a[1][1] * (a[2][0] * a[3][2] - a[2][2] * a[3][0]) + a[1][2] * (a[2][0] * a[3][1] - a[2][1] * a[3][0]));
			int d = s1 - s2 + s3 - s4;
			printf("%d\n", d);

			s1 = b[0][0] * (b[1][1] * (b[2][2] * b[3][3] - b[3][2] * b[2][3]) - b[1][2] * (b[2][1] * b[3][3] - b[2][3] * b[3][1]) + b[1][3] * (b[2][1] * b[3][2] - b[2][2] * b[3][1]));
			s2 = b[0][1] * (b[1][0] * (b[2][2] * b[3][3] - b[3][2] * b[2][3]) - b[1][2] * (b[2][0] * b[3][3] - b[2][3] * b[3][0]) + b[1][3] * (b[2][0] * b[3][2] - b[2][2] * b[3][0]));
			s3 = b[0][2] * (b[1][0] * (b[2][1] * b[3][3] - b[3][1] * b[2][3]) - b[1][1] * (b[2][0] * b[3][3] - b[2][3] * b[3][0]) + b[1][3] * (b[2][0] * b[3][1] - b[2][1] * b[3][0]));
			s4 = b[0][3] * (b[1][0] * (b[2][1] * b[3][2] - b[3][1] * b[2][2]) - b[1][1] * (b[2][0] * b[3][2] - b[2][2] * b[3][0]) + b[1][2] * (b[2][0] * b[3][1] - b[2][1] * b[3][0]));
			d = s1 - s2 + s3 - s4;
			printf("%d\n", d);
		}

		if (ch == 't') {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					c[i][j] = a[j][i];
				}
			}

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					d[i][j] = b[j][i];
				}
			}

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", c[i][j]);
				}
				printf("\n");
			}

			printf("\n");

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", d[i][j]);
				}
				printf("\n");
			}
		}

		if (ch == 'e') {

			if (count == 1) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (a[i][j] % 2 == 0) {
							printf("%d ", a[i][j]);
						}
						else {
							printf("  ");
						}
					}
					printf("\n");
				}

				printf("\n");

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (b[i][j] % 2 == 0) {
							printf("%d ", b[i][j]);
						}
						else {
							printf("  ");
						}
					}
					printf("\n");
				}

				printf("\n");
			}

			if (count == 2) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (a[i][j] == 1) {
							printf("%d ", a[i][j]);
						}
						else {
							printf("  ");
						}
					}
					printf("\n");
				}

				printf("\n");

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (b[i][j]==1) {
							printf("%d ", b[i][j]);
						}
						else {
							printf("  ");
						}
					}
					printf("\n");
				}

				printf("\n");
			}

			if (count == 3) {
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
			}

			count++;
			if (count > 3) {
				count = 1;
			}
		}

		if (ch == 's') {

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

			
			
		}

		if (ch>=48 && ch<=57) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", a[i][j]*((int)ch-48));
				}
				printf("\n");
			}

			printf("\n");

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d ", b[i][j]* ((int)ch - 48));
				}
				printf("\n");
			}

			printf("\n");
		}

	}

	return 0;
}