#pragma once

enum TYPES { GO, DRAW, WIN_O, WIN_X };
enum LINES { DIAG_UP, DIAG_DOWN, LINE_H, LINE_V };
class  Board {
private:
    int field[10][10];
    bool checker(int *mas, const int l) const;
    int linearize(const int x, const int y, int *ans, const int type) const;
    bool check(const int x, const int y) const;
    void getter(const int x, const int y, const int dx, const int dy, int *ans, const int sign_1, const int sign_2) const;
public:
    Board();
    int get_cell(const int x, const int y) const;
    bool move(const int x, const  int y, const int sign);
    bool canMove(const int x, const  int y, const char sign) const;
    TYPES isWin() const;

};
