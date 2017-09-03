#pragma once
#include <ncurses.h>
#include "Board.h"

class NcursesView {
private:
    Board &b;
    int cur_move;
public:
    NcursesView(Board &b);
    ~NcursesView();
    void showBoard() const;
    void doGameCycle();
};
