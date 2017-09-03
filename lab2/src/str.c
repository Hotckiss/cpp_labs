#include "../include/str.h"

char * strcpy(char * destination, const char * source) {
    int i = 0;
    while (*(source + i) != '\0') {
        *(destination + i) = *(source + i);
	i = i + 1;
    }
    *(destination + i) = '\0';
    return destination;
}

char * strcat(char * destination, const char * source) {
    int i = 0, j = 0;
    while (*(destination + i) != '\0')
	i = i + 1;
    while (*(source + j) != '\0') {
        *(destination + i + j) = *(source + j);
	j = j + 1;
    }
    *(destination + i + j) = '\0';
    return destination;
}
size_t strlen(const char * str) {
    int i = 0;
    while (*(str + i) != '\0')
	i = i + 1;
    return i;
}
int strcmp(const char * str1, const char * str2) {
    int i = 0;
    while (*(str1 + i) != '\0' && *(str2 + i) != '\0' && *(str1 + i) == *(str2 + i))
        i = i + 1;
    if (*(str1 + i) > *(str2 + i)) // aaab and aaa
        return 1;
    else if (*(str1 + i) == *(str2 + i)) // aaab and aaa
        return 0;
    else
        return -1;
}

