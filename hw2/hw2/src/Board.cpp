#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include "Board.h"
Board::Board() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            field[i][j] = '.';
}
int Board::get_cell(const int x, const int y) const {
    assert(x >= 0 && y >= 0 && x < 10 && y < 10);
    return field[y][x];
}
bool Board::canMove(const int x, const  int y, const char sign) const{
    if (!(x >= 0 && y >= 0 && x < 10 && y < 10)) return false;
    if(get_cell(x, y) != '.') return false;
    return true;
}
bool Board::move(const int x, const int y, const int sign) {
    if (canMove(x, y, '?')) {
        field[y][x] = sign;
        return true;
    }
    return false;
}
void Board::getter(const int x, const int y, const int dx, const int dy, int *ans, const int sign_1, const int sign_2) const {
	for (int i = 0; i <= dx + dy; i++)
		ans[i] = get_cell(x + sign_1 * i, y + sign_2 * i);
}
int Board::linearize(const int x, const int y, int *ans, const int type) const {
    int dx, dy;
	switch(type) {
		case DIAG_UP:
			dx = std::min(4, std::min(x, y)), dy = std::min(4, std::min(9 - x, 9 - y));
			getter(x - dx, y - dx, dx, dy, ans, 1, 1);
			break;
		case DIAG_DOWN:
			dx = std::min(4, std::min(x, 9 - y)), dy = std::min(4, std::min(9 - x, y));
			getter(x - dx, y + dx, dx, dy, ans, 1, -1);
			break;
		case LINE_H:
			dx = std::min(4, x), dy = std::min(4, 9 - x);
			getter(x - dx, y, dx, dy, ans, 1, 0);
			break;
		case LINE_V:
			dx = std::min(4, y), dy = std::min(4, 9 - y);
			getter(x, y - dx, dx, dy, ans, 0, 1);
			break;
	}
    return dx + dy + 1;
}
bool Board::checker(int *mas, const int l) const {
    int cnt = 1;
    if (mas[0] == '.') cnt--;
    for (int i = 1; i < l; i++) {
        if (cnt == 5) return true;
        if (mas[i] == '.') cnt = 0;
        else if (mas[i] == mas[i - 1]) cnt++;
        else cnt = 1;
    }
    if (cnt == 5) return true;
    return false;
}
bool Board::check(const int x, const int y) const {
    int d1[10];
    bool res = false;
    for (int it = 0; it < 4; it++) {
        for (int i = 0; i < 10; i++) d1[i] = 0;
        int l1 = linearize(x, y, d1, it);
        if (checker(d1, l1)) res = true;
    }
    return res;
}
TYPES Board::isWin() const{
    int flag = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (get_cell(i, j) == '.') flag = 1;
            else if (check(i, j))
                return (get_cell(i, j) == 'X') ? WIN_X : WIN_O;
        }
    return flag ? GO : DRAW;
}
