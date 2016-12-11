#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "BoardView.h"
int a[15];
int main(int argc, char *argv[]) {
    Board b(10, 10, 5);
    srand(time(NULL));
    //b.cheats();
    View tv(b);
    tv.showBoard();
    tv.doGameCycle();
    printf("Hello\n");
    //0 go 1draw 2o 3x
    return 0;
} // 0..xx.00