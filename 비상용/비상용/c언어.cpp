#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 30

bool pathOX = false;
bool mal = false;
int objX = 0, objY = 0;
int dx = 0, dy = 0;
int num = 0;

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void generateRandomGrid(char grid[SIZE][SIZE]) {
    srand((unsigned)time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = '1';  
        }
    }

    int pathLength = (SIZE * SIZE) / 2 + 70;
    int pathCount = 0;

    while (pathCount < pathLength) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (grid[x][y] == '1') {  
            grid[x][y] = '0';  
            pathCount++;
        }
    }

    int obstacles = 0;
    while (obstacles < 30) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (grid[x][y] == '1') {  
            grid[x][y] = 'X';
            obstacles++;
        }
    }

    grid[0][0] = '0';  
    grid[SIZE - 1][SIZE - 1] = '0'; 
}

void readPathFromFile(char grid[SIZE][SIZE]) {
    FILE* file = NULL;

    if (num == 0) {
        file = fopen("path.txt", "r");
    }

    if (num == 1) {
        file = fopen("path1.txt", "r");
    }


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

void reverseDirection() {
    if (dx != 0) {
        dx = -dx;
    }
    if (dy != 0) {
        dy = -dy;
    }
    objX += dx;
    objY += dy;
}

int main() {
    char grid[SIZE][SIZE];
    char command;

    //generateRandomGrid(grid);  
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
            dx = 0;
            dy = 0;
        }

        else if (command == 'W' || command == 'w') {
            dx = -1;
            dy = 0;
            if (Move(grid, objX - 1, objY)) {
                objX--;
            }
            else if (grid[objX - 1][objY] == 'X') {
                reverseDirection();
            }
        }

        else if (command == 'S' || command == 's') {
            dx = 1;
            dy = 0;
            if (Move(grid, objX + 1, objY)) {
                objX++;
            }
            else if (grid[objX + 1][objY] == 'X') {
                reverseDirection();
            }
        }

        else if (command == 'A' || command == 'a') {
            dx = 0;
            dy = -1;
            if (Move(grid, objX, objY - 1)) {
                objY--;
            }
            else if (grid[objX][objY - 1] == 'X') {
                reverseDirection();
            }
        }

        else if (command == 'D' || command == 'd') {
                dx = 0;
                dy = 1;
                if (Move(grid, objX, objY + 1)) {
                    objY++;
                }
                else if (grid[objX][objY + 1] == 'X') {
                    reverseDirection();
                }
            }

        else if (command == 'Q' || command == 'q') {
                break;
            }

        else if (command == 'u' || command == 'U') {
            //generateRandomGrid(grid);
            objX = 0, objY = 0;
            num++;
            readPathFromFile(grid);
        }

        }

    

    return 0;
}
