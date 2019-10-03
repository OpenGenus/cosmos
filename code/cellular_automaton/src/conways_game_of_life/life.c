#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Part of Cosmos by OpenGenus Foundation
#define width 40
#define height 30

const char* clear = "\e[1;1H\e[2J";

int main(){
    srand(time(NULL));

    int board[height][width];
    int temp[height][width];

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j] = rand() % 2;
        }
    }

    memcpy(temp, board, sizeof(int) * width * height);

    while (1) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                putc(32 + 16 * board[i][j], stdout);
            }
            putc('\n', stdout);
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int sum = board[(i + 1) % height][(j + 1) % width] +
                          board[(i + 1) % height][j] +
                          board[(i + 1) % height][(j + width - 1) % width] +
                          board[i][(j + 1) % width] +
                          board[i][(j + width - 1) % width] +
                          board[(i + height - 1) % height][(j + 1) % width] +
                          board[(i + height - 1) % height][j] +
                          board[(i + height - 1) % height][(j + width - 1) % width];

                temp[i][j] = (temp[i][j] && sum >= 2 && sum <= 3) || sum == 3;
            }
        }
        memcpy(board, temp, sizeof(int) * width * height);
        getchar();
        printf("%s", clear);
    }
    return 0;
}
