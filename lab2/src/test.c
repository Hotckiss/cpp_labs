#include "../include/test_str.h"

int main() {
    if(test_strcpy() && test_strcat() && test_strcmp() && test_strlen())
        printf("All functions are correct!");
    else
        printf("Bad functions.");
    return 0;
}