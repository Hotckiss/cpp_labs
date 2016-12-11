#pragma once
#include "Board.h"

class View {
private:
    Board &b;
    int cur_move;
public:
    View(Board &b);
    //~View();
    //View(const View & b);
    //View & operator=(const View & b);
    void showBoard(); //вывод доски на экран
    void doGameCycle(); //основной цикл игры: ввод хода, вывод на экран доски, проверка текущего состояния
};
