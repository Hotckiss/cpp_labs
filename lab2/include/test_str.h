#ifndef __TEST_STR_H_
#define __TEST_STR_H_

#include <stdlib.h> //for rand()
#define TEST_COUNT 100 // number of tests
int gen_str(char *s); //generate randon len string
void gen_null(char *s); // generate empty string
int check_test_strcpy(char *s1, char *s2);
int test_strcpy(void);
int check_test_strcat(char *s1, char *s2, char *s3);
int test_strcat(void);
int test_strcmp(void);
int test_strlen(void);
#endif
