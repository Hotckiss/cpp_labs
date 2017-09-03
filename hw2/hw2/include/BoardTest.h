#pragma once
#include "Test.h"
#include "Board.h"
class BoardTest: public Test {
public:
    void testisWin_go();
    void testisWin_draw();
    void testisWin_winx();
    void testisWin_wino();
    void testisWin_hard_checker_diagonal_win_1();
    void testisWin_hard_checker_diagonal_win_2();
    void testisWin_hard_checker_diagonal_win_3();
    void testisWin_hard_checker_diagonal_win_4();
    void testisWin_hard_checker_diagonal_win_5();
    void testisWin_hard_checker_diagonal_win_6();
    void testisWin_hard_checker_diagonal_win_7();
    void testisWin_hard_checker_line_win_1();
    void testisWin_hard_checker_line_win_2();
    void testisWin_hard_checker_line_win_3();
    void testisWin_hard_checker_line_win_4();
    void testisWin_hard_checker_line_win_5();
    void testisWin_hard_checker_line_win_6();
    void testisWin_hard_checker_line_win_7();
    void testcanMove_easy_1();
    void testcanMove_easy_2();
    void testcanMove_easy_3();
    void testcanMove_easy_4();
    void testcanMove_easy_5();
    void testcanMove_easy_6();
    void testcanMove_easy_7();
    void testmove_easy_1();
    void testmove_easy_2();
    void testmove_easy_3();
    void testget_easy_1();
    void testget_easy_2();
    void testget_easy_3();
    void runAllTests();
};
