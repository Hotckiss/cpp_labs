#pragma once
#include "Board.h"

class View {
private:
    Board &b;
    int cur_move;
    int is_silent;
public:
    View(Board &b, int is_silent);
    void showBoard() const;
    void doGameCycle();
};
