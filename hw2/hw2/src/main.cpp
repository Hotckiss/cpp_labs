#include <cstring>
#include "NcursesBoardView.h"
#include "BoardView.h"
int main(int argc, char *argv[]) {
    int is_silent = 0;
    Board b;
    if(argc > 1 && !strcmp(argv[1], "curses")) {
        initscr();
        keypad(stdscr, true);
        noecho();
        NcursesView tv(b);
        tv.doGameCycle();
	getch();
        endwin();
        return 0;
    }
    else if(argc > 1 && !strcmp(argv[1], "silent"))
        is_silent = 1;
    View tv(b, is_silent);
    tv.doGameCycle(); 
    return 0;
}
