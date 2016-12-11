#include <cassert>
#include <algorithm>
#include <cstdlib>
#include "Board.h"

Board::Board(int w, int h, int to_win) : w(w), h(h), to_win(to_win) {
    assert(to_win < std::max(w, h));
    int *buffer = new int[w * h]();
    field = new int*[h];
    for (int i = 0; i < h; i++)
        field[i] = buffer + i * w;
    //cur_move = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            field[i][j] = '.';
}
Board::Board(const Board & b) {
    delete[] *field;
    delete[] field;
    w = b.w;
    h = b.h;
    to_win = b.to_win;
    //cur_move = b.cur_move;
    int *buffer = new int[w * h]();
    field = new int*[h];
    for (int i = 0; i < h; i++)
        field[i] = buffer + i * w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            field[i][j] = b.field[i][j];
}
Board::~Board() {
    delete[] *field;
    delete[] field;
}
int Board::get_w() const {
    return w;
}
int Board::get_h() const {
    return h;
}
void Board::swap(Board & b) {
    std::swap(field, b.field);
    std::swap(w, b.w);
    std::swap(h, b.h);
    std::swap(to_win, b.to_win);
    //std::swap(cur_move, b.cur_move);
}
Board & Board::operator=(const Board & b) {
    assert(this != &b);
    Board(b).swap(*this);
    return *this;
}
int Board::get_cell(const int x, const int y) const {
    assert(x >= 0 && y >= 0 && x < w && y < h);
    return field[y][x];
}
bool Board::canMove(int x, int y, char sign) {
    //if(sign != '')
    if (!(x >= 0 && y >= 0 && x < w && y < h)) return false;
    if(get_cell(x, y) != '.') return false;
    return true;
}
bool Board::move(int x, int y, int sign) {
    if (canMove(x, y, '?')) {
        field[y][x] = sign;
        return true;
    }
    printf("Bad move!\n");
    return false;
}
/*void Board::cheats() {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            int r = rand() % 3;
            if (!r) field[i][j] = '.';
            else if(r == 1) field[i][j] = 'X';
            else field[i][j] = 'O';
        }
}
void Board::print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            printf("%c ", field[i][j]);
        printf("\n");
    }
}*/
int Board::linearize(const int x, const int y, int *ans, const int type) const {
    int dx, dy;
    if (type == 0) {
        dx = std::min(to_win - 1, std::min(x, y)), dy = std::min(to_win - 1, std::min(w - 1 - x, h - 1 - y));
        for (int i = 0; i <= dx + dy; i++)
            ans[i] = get_cell(x - dx + i, y - dx + i);
    }
    else if (type == 1) {
        dx = std::min(to_win - 1, std::min(x, h - 1 - y)), dy = std::min(to_win - 1, std::min(w - 1 - x, y));
        for (int i = 0; i <= dx + dy; i++)
            ans[i] = get_cell(x - dx + i, y + dx - i);
    }
    else if (type == 2) {
        dx = std::min(to_win - 1, x), dy = std::min(to_win - 1, w - 1 - x);
        for (int i = 0; i <= dx + dy; i++)
            ans[i] = get_cell(x - dx + i, y);
    }
    else {
        dx = std::min(to_win - 1, y), dy = std::min(to_win - 1, h - 1 - y);
        for (int i = 0; i <= dx + dy; i++)
            ans[i] = get_cell(x, y - dx + i);
    }
    return dx + dy + 1;
}
bool Board::checker(int *mas, const int l) const {
    int cnt = 1;
    if (mas[0] == '.') cnt--;
    for (int i = 1; i < l; i++) {
        if (cnt == to_win) return true;
        if (mas[i] == '.') cnt = 0;
        else if (mas[i] == mas[i - 1]) cnt++;
        else cnt = 1;
    }
    return false;
}
bool Board::check(const int x, const int y) const {
    int *d1 = new int[2 * to_win];
    bool res = false;
    //int d1[27];
    for (int it = 0; it < 4; it++) {
        for (int i = 0; i < 2 * to_win; i++) d1[i] = 0;
        int l1 = linearize(x, y, d1, it);
        if (checker(d1, l1)) res = true;
    }
    delete[] d1;
    return res;
}
TYPES Board::isWin() {
    int flag = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (get_cell(i, j) == '.') flag = 1;
            else if (check(i, j))
                return (get_cell(i, j) == 'X') ? WIN_X : WIN_O;
        }
    return flag ? GO : DRAW;
}