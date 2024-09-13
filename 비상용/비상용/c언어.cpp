#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 30

bool pathOX = false;
bool mal = false;

int objX = 0, objY = 0;

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void readPathFromFile(char grid[SIZE][SIZE]) {
    FILE* file = fopen("path.txt", "r");

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            char ch = fgetc(file);
            if (ch == ' ') {
                j--;
                continue;
            }
            grid[i][j] = ch;
        }
        fgetc(file);
    }

    fclose(file);
}

void printGrid(char grid[SIZE][SIZE], int objX, int objY) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i == objX && j == objY && mal == true) {
                printf(RED "# " RESET);
            }
            else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

bool Move(char grid[SIZE][SIZE], int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && grid[x][y] == '0');
}

int main() {
    char grid[SIZE][SIZE];
    char command;

    readPathFromFile(grid);

    while (1) {
        if (pathOX) {
            system("cls");
            printGrid(grid, objX, objY);
        }

        scanf(" %c", &command);

        if (command == 't') {
            pathOX = true;
        }

        else if (command == 'R' || command == 'r') {
            mal = true;
            objX = 0;
            objY = 0;
        }

        else if (command == 'W' || command == 'w') {
            if (Move(grid, objX - 1, objY)) {
                objX--;
            }
        }
        else if (command == 'S' || command == 's') {
            if (Move(grid, objX + 1, objY)) {
                objX++;
            }
        }
        else if (command == 'A' || command == 'a') {
            if (Move(grid, objX, objY - 1)) {
                objY--;
            }
        }
        else if (command == 'D' || command == 'd') {
            if (Move(grid, objX, objY + 1)) {
                objY++;
            }
        }
        else if (command == 'Q' || command == 'q') {
            break;
        }
    }

    return 0;
}
