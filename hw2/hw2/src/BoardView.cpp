#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include "BoardView.h"

View::View(Board &b, int is_silent) : b(b), cur_move(0), is_silent(is_silent) {}
void View::showBoard() const {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%c", b.get_cell(i, j));
        printf("\n");
    }
}
void View::doGameCycle() {
    while (b.isWin() == GO) {
        int mx, my;
		if(!is_silent) showBoard();
        printf("%c move: ", cur_move ? 'X' : 'O');
        scanf("%i %i", &mx, &my);
		if(mx == -1 && my == -1) break;
        while (!b.move(mx, my, cur_move ? 'X' : 'O')) {
	    printf("Bad move!\n");
		printf("%c move: ", cur_move ? 'X' : 'O');
        scanf("%i %i", &mx, &my);
	}
        if (b.isWin() == (cur_move ? WIN_X : WIN_O)) {
			showBoard();
            printf("%c wins!\n", cur_move ? 'X' : 'O');
            break;
        }
        if (b.isWin() == DRAW) {
			showBoard();
            printf("Draw.\n");
            break;
        }
        cur_move = !cur_move;
    }
}
