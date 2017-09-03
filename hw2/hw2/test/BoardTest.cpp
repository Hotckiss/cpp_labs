#include "BoardTest.h"
void BoardTest::testisWin_go() {
    Board b;
    char fld[10][10] = { {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', '.', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'}
    };
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == GO);
}
void BoardTest::testisWin_draw() {
    Board b;
    char fld[10][10] = { {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == DRAW);
}
void BoardTest::testisWin_wino() {
    Board b;
    char fld[10][10] = { {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'}
    						
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testisWin_winx() {
    Board b;
    char fld[10][10] = { {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                         {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
                         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'}
    
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_diagonal_win_1() {
    Board b;
    char fld[10][10] = { {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', 'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', 'X', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', 'O', 'O', 'O', 'O', '.', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_diagonal_win_2() {
    Board b;
    char fld[10][10] = { {'O', '.', 'X', '.', '.', 'X', '.', '.', '.', '.'},
                         {'.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.'},
                         {'X', '.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
                         {'.', '.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
                         {'.', '.', '.', '.', 'X', '.', 'O', '.', '.', 'X'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'O', 'O', '.', 'O', 'O', 'O', 'O', '.', 'O', '.'},
                         {'.', '.', '.', 'O', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'O', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_diagonal_win_3() {
    Board b;
    char fld[10][10] = { {'X', '.', '.', '.', '.', 'X', '.', '.', '.', 'O'},
                         {'.', 'X', '.', 'X', '.', '.', '.', '.', 'O', '.'},
                         {'.', '.', 'O', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', 'X', '.', '.', 'O', '.', '.', '.'},
                         {'.', 'X', '.', '.', 'X', 'O', '.', 'X', 'X', '.'},
                         {'.', '.', '.', '.', 'O', 'X', '.', '.', '.', '.'},
                         {'.', 'X', '.', 'O', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', 'O', 'O', 'O', 'O', 'O', 'X', 'O', '.'},
                         {'.', 'O', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', 'X', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        if(fld[i][j] != '.')
            b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testisWin_hard_checker_diagonal_win_4() {
    Board b;
    char fld[10][10] = { {'X', '.', '.', '.', '.', '.', 'X', '.', '.', '.'},
                         {'.', 'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', 'X', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', 'O', '.', '.', '.'},
                         {'.', 'X', '.', '.', '.', 'O', '.', '.', '.', '.'},
                         {'.', 'X', '.', '.', 'O', '.', '.', '.', '.', '.'},
                         {'.', 'X', '.', 'O', 'O', 'O', 'O', '.', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testisWin_hard_checker_diagonal_win_5() {
    Board b;
    char fld[10][10] = { {'X', '.', '.', '.', 'X', '.', '.', '.', '.', 'O'},
                         {'.', 'X', '.', 'X', '.', '.', '.', '.', '.', 'O'},
                         {'.', '.', 'X', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', 'X', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', 'O', 'O', 'O', 'O', '.', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_diagonal_win_6() {
    Board b;
    char fld[10][10] = { {'X', '.', 'O', '.', 'X', '.', '.', 'O', '.', 'O'},
                         {'.', 'X', '.', 'X', '.', 'O', 'O', '.', '.', 'O'},
                         {'.', '.', 'O', '.', 'O', '.', '.', 'O', '.', '.'},
                         {'.', 'X', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'X', '.', '.', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', 'X', 'X', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', 'X', 'X', 'O', 'O', 'O', 'O', '.', 'O', '.'},
                         {'.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_diagonal_win_7() {
    Board b;
    char fld[10][10] = { {'X', '.', 'O', '.', 'X', '.', '.', 'O', '.', 'O'},
                         {'.', 'X', '.', 'X', '.', 'O', 'O', '.', '.', 'O'},
                         {'.', '.', 'O', '.', 'O', '.', '.', 'O', '.', '.'},
                         {'.', 'X', '.', 'X', '.', '.', '.', '.', '.', '.'},
                         {'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', 'O', '.', 'X'},
                         {'.', '.', 'X', '.', '.', '.', '.', '.', 'X', '.'},
                         {'.', 'X', '.', 'O', 'O', 'O', 'O', 'X', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', 'X', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', 'X', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_line_win_1() {
    Board b;
    char fld[10][10] = { {'.', '.', '.', '.', '.', '.', '.', 'X', '.', '.'},
                         {'.', '.', 'X', '.', '.', '.', '.', '.', 'X', '.'},
                         {'.', '.', '.', '.', '.', '.', 'X', '.', '.', '.'},
                         {'.', 'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', 'X', 'X', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testisWin_hard_checker_line_win_2() {
    Board b;
    char fld[10][10] = { {'O', '.', '.', '.', 'X', '.', '.', '.', 'O', '.'},
                         {'.', 'O', '.', '.', 'X', '.', '.', 'O', '.', '.'},
                         {'.', '.', 'O', '.', 'X', '.', 'O', '.', '.', '.'},
                         {'.', '.', '.', 'O', 'X', 'O', '.', '.', '.', '.'},
                         {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '.'},
                         {'.', '.', '.', 'O', 'X', 'O', '.', '.', '.', '.'},
                         {'.', '.', 'O', '.', 'X', '.', 'O', '.', '.', '.'},
                         {'.', 'O', '.', '.', 'X', '.', '.', 'O', '.', '.'},
                         {'O', '.', '.', '.', 'X', '.', '.', '.', 'O', '.'},
                         {'.', '.', '.', '.', 'O', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_line_win_3() {
    Board b;
    char fld[10][10] = { {'X', 'X', 'X', 'X', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', 'O', '.', '.', 'O', '.', '.', '.'},
                         {'.', '.', '.', '.', 'O', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', 'O', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'O', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_line_win_4() {
    Board b;
    char fld[10][10] = { {'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_line_win_5() {
    Board b;
    char fld[10][10] = { {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', 'O', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', 'O', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_X);
}
void BoardTest::testisWin_hard_checker_line_win_6() {
    Board b;
    char fld[10][10] = { {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'O', 'O', 'O', 'O', 'O', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testisWin_hard_checker_line_win_7() {
    Board b;
    char fld[10][10] = { {'O', 'O', 'O', 'O', '.', '.', '.', '.', '.', '.'},
                         {'O', 'O', 'O', 'O', '.', '.', '.', '.', '.', '.'},
                         {'O', 'O', 'O', 'O', '.', '.', '.', '.', '.', '.'},
                         {'O', 'O', 'O', 'O', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', 'O', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '.', '.', '.', '.', '.', 'X', 'X', 'X', 'X'},
                         {'.', '.', '.', '.', '.', '.', 'X', 'X', 'X', 'X'},
                         {'.', '.', '.', '.', '.', '.', 'X', 'X', 'X', 'X'},
                         {'.', '.', '.', '.', '.', '.', 'X', 'X', 'X', 'X'}
    };
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(fld[i][j] != '.')
                b.move(i, j, fld[i][j]);
    DO_CHECK(b.isWin() == WIN_O);
}
void BoardTest::testcanMove_easy_1() {
    Board b;
    b.canMove(-1, 0, 'X');
    DO_CHECK(b.canMove(-1, 0, 'X') == false);
}
void BoardTest::testcanMove_easy_2() {
    Board b;
    DO_CHECK(b.canMove(0, -1, 'X') == false);
}
void BoardTest::testcanMove_easy_3() {
    Board b;
    DO_CHECK(b.canMove(1000, 0, 'X') == false);
}
void BoardTest::testcanMove_easy_4() {
    Board b;
    DO_CHECK(b.canMove(0, 1110, 'X') == false);
}
void BoardTest::testcanMove_easy_5() {
    Board b;
    b.move(5, 5, 'X');
    DO_CHECK(b.canMove(5, 5, 'O') == false);
}
void BoardTest::testcanMove_easy_6() {
    Board b;
    b.move(5, 5, 'X');
    DO_CHECK(b.canMove(5, 5, 'X') == false);
}
void BoardTest::testcanMove_easy_7() {
    Board b;
    DO_CHECK(b.canMove(5, 5, 'X') == true);
}
void BoardTest::testmove_easy_1() {
    Board b;
    b.move(0, 0, 'X');
    DO_CHECK(b.get_cell(0, 0) == 'X');
}
void BoardTest::testmove_easy_2() {
    Board b;
    b.move(9, 9, 'O');
    DO_CHECK(b.get_cell(9, 9) == 'O');
}
void BoardTest::testmove_easy_3() {
    Board b;
    b.move(5, 5, 'X');
    DO_CHECK(b.get_cell(5, 5) == 'X');
}
void BoardTest::testget_easy_1() {
    Board b;
    b.move(7, 7, 'X');
    DO_CHECK(b.get_cell(7, 7) == 'X');
}
void BoardTest::testget_easy_2() {
    Board b;
    b.move(7, 7, 'O');
    DO_CHECK(b.get_cell(7, 7) == 'O');
}
void BoardTest::testget_easy_3() {
    Board b;
    DO_CHECK(b.get_cell(7, 7) == '.');
}
void BoardTest::runAllTests() {
    testisWin_go();
    testisWin_draw();
    testisWin_winx();
    testisWin_wino();
    testisWin_hard_checker_diagonal_win_1();
    testisWin_hard_checker_diagonal_win_2();
    testisWin_hard_checker_diagonal_win_3();
    testisWin_hard_checker_diagonal_win_4();
    testisWin_hard_checker_diagonal_win_5();
    testisWin_hard_checker_diagonal_win_6();
    testisWin_hard_checker_diagonal_win_7();
    testisWin_hard_checker_line_win_1();
    testisWin_hard_checker_line_win_2();
    testisWin_hard_checker_line_win_3();
    testisWin_hard_checker_line_win_4();
    testisWin_hard_checker_line_win_5();
    testisWin_hard_checker_line_win_6();
    testisWin_hard_checker_line_win_7();
    testcanMove_easy_1();
    testcanMove_easy_2();
    testcanMove_easy_3();
    testcanMove_easy_4();
    testcanMove_easy_5();
    testcanMove_easy_6();
    testcanMove_easy_7();
    testmove_easy_1();
    testmove_easy_2();
    testmove_easy_3();
    testget_easy_1();
    testget_easy_2();
    testget_easy_3();
}
