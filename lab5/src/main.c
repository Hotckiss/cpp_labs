#include <stdio.h>
#include <string.h>
#include "../include/position.h"
#include "../include/apply.h"
int main(int argc, char* argv[]) {
    intrusive_list mylist;
    FILE *F;
    int cnt;
    init_list(&mylist);
    if (!strcmp(argv[1], "loadtext"))
       loadtxt(&mylist, argv[2]);
    else
       loadbin(&mylist, argv[2]);
    if (!strcmp(argv[3], "print"))
        apply(&mylist, print, argv[4]);
    else if (!strcmp(argv[3], "count"))
        cnt = 0, apply(&mylist, count, &cnt), printf("%i\n", cnt);
    else if(!strcmp(argv[3], "savetext"))
        F = fopen(argv[4], "wt"), apply(&mylist, savetxt, F), fclose(F);
    else
        F = fopen(argv[4], "wb"), apply(&mylist, savebin, F), fclose(F);
    remove_all(&mylist);
    return 0;
}
//ConsoleApplication7.exe loadtxt test1.txt print "[%d; %d] "
//ConsoleApplication7.exe loadtxt test1.txt savebin testbin2.txt
//ConsoleApplication7.exe loadbin testbin2.txt print "[%d; %d] "
