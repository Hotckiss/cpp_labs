#pragma once

enum TYPES { GO, DRAW, WIN_O, WIN_X };

class  Board {
private:
    int **field;
    int w, h;
    int to_win;
    bool checker(int *mas, const int l) const;
    int linearize(const int x, const int y, int *ans, const int type) const;
    bool check(const int x, const int y) const;
public:
    Board(int w, int h, int to_win);
    Board(const Board & b);
    ~Board();
    void swap(Board & b);
    Board & operator=(const Board & b);
    int get_cell(const int x, const int y) const;
    int get_w() const;
    int get_h() const;
    bool move(int x, int y, int sign); //������� ���
    bool canMove(int x, int y, char sign); //��������� �� ���
    TYPES isWin(); // ������� ���������: ������ ������; �����; 0 ��������; X ��������
                 //����� ��������� ������ ��� �������������.
    //void cheats();
    //void print();
};
