#ifndef __STR_H_
#define __STR_H_

#include <stdio.h> // for size_t type
#define MAX_STR 10000 // max size of string
char * strcpy(char * destination, const char * source); // copy source in dest
char * strcat(char * destination, const char * source); // dest + source
int strcmp(const char * str1, const char * str2); // compare str1 fnd str2
size_t strlen(const char * str); // string lenght
#endif
