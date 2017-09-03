#include "NcursesBoardView.h"

NcursesView::NcursesView(Board &b) : b(b), cur_move(0) {}
NcursesView::~NcursesView() {}
void NcursesView::showBoard() const {
    move(0, 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printw("%c", b.get_cell(i, j));
        printw("\n");
    }
    refresh();
}
void NcursesView::doGameCycle() {
    int pos_x = 0, pos_y = 0, ch;
    move(pos_y, pos_x);
    while (b.isWin() == GO) {
        showBoard();
	printw("%c move.", cur_move ? 'X' : 'O');
        move(pos_y, pos_x);
        ch = getch();
        if(ch == 'x') break;
        else if(ch == KEY_UP) { 
            if(pos_y > 0) move(--pos_y, pos_x); 
            continue; 
            }
        else if(ch == KEY_DOWN) {
            if(pos_y < 9) move(++pos_y, pos_x); 
            continue;
        }
        else if(ch == KEY_LEFT) {
            if(pos_x > 0) move(pos_y, --pos_x);
            continue;
        }
        else if(ch == KEY_RIGHT) {
            if(pos_x < 9) move(pos_y, ++pos_x); 
            continue; 
        }
        else if(ch == ' ') {
            if(!b.move(pos_y, pos_x, cur_move ? 'X' : 'O')) continue;
        }
        else continue;
        refresh();
        if (b.isWin() == (cur_move ? WIN_X : WIN_O)) {
            showBoard();
            printw("%c wins!\n", cur_move ? 'X' : 'O');
            refresh();
            break;
        }
        if (b.isWin() == DRAW) {
            showBoard();
            printw("Draw.\n");
            refresh();
            break;
        }
        cur_move = !cur_move;
    }
}
