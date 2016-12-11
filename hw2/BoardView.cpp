#include <cassert>
#include <algorithm>
#include <cstdlib>
#include "BoardView.h"

View::View(Board &b) : b(b), cur_move(0) {}
//View::~View() { ~Board();  }
void View::showBoard() {
    for (int i = 0; i < b.get_h(); i++) {
        for (int j = 0; j < b.get_w(); j++)
            printf("%c ", b.get_cell(i, j));
        printf("\n");
    }
}
void View::doGameCycle() {
    while (b.isWin() == GO) {
        int mx, my;
        printf("%c move: ", cur_move ? 'X' : 'O');
        scanf("%i %i", &mx, &my);
        if (!b.move(mx, my, cur_move ? 'X' : 'O')) continue;
        showBoard();
        if (b.isWin() == (cur_move ? WIN_X : WIN_O)) {
            printf("%c wins!\n", cur_move ? 'X' : 'O');
            break;
        }
        if (b.isWin() == DRAW) {
            printf("Draw!\n");
            break;
        }
        cur_move = !cur_move;
    }
}