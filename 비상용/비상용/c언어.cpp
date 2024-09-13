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

bool isValidMove(char grid[SIZE][SIZE], int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && grid[x][y] == '0');
}

void moveObject(char grid[SIZE][SIZE], char direction) {
    int dx = 0, dy = 0;

    if (direction == 'W' || direction == 'w') {
        dx = -1;  // Move up
    }
    else if (direction == 'S' || direction == 's') {
        dx = 1;   // Move down
    }
    else if (direction == 'A' || direction == 'a') {
        dy = -1;  // Move left
    }
    else if (direction == 'D' || direction == 'd') {
        dy = 1;   // Move right
    }

    while (1) {
        int newX = objX + dx;
        int newY = objY + dy;

        if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE || grid[newX][newY] == '1') {
            // Stop if we hit the boundary or a '1'
            break;
        }

        if (grid[newX][newY] == 'X') {
            // Reverse direction if we hit an 'X'
            dx = -dx;
            dy = -dy;
        }

        objX = newX;
        objY = newY;

        printGrid(grid, objX, objY);
    }
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

        if (command == 'R' || command == 'r') {
            mal = true;
            objX = 0;
            objY = 0;
        }
        else if (command == 'W' || command == 'w' || command == 'A' || command == 'a' || command == 'S' || command == 's' || command == 'D' || command == 'd') {
            moveObject(grid, command);
        }
        else if (command == 'Q' || command == 'q') {
            break;
        }
    }

    return 0;
}
