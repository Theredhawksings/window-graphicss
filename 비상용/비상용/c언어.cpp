#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

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

void printGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[SIZE][SIZE];
    int objX = 0, objY = 0;
    char command;

    readPathFromFile(grid);

    printGrid(grid);

    return 0;
}




