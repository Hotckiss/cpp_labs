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
    void showBoard(); //����� ����� �� �����
    void doGameCycle(); //�������� ���� ����: ���� ����, ����� �� ����� �����, �������� �������� ���������
};
