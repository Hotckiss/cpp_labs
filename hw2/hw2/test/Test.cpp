#include "Test.h"
int Test::totalNum;
int Test::failedNum;
void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    if(!expr) {
        printf("test failed: %s in %s:%zu\n", func, filename, lineNum);
        failedNum++; 
    }
    totalNum++;
}

void Test::showFinalResult() {
    if(!failedNum) printf("All test passed.\n");
    else printf("Failed %i of %i tests.\n", failedNum, totalNum);
}

