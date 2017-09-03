#include "../include/str.h"
#include "../include/test_str.h"


int gen_str(char *s) {
    int i = 0;
    int len = (rand() % (MAX_STR / 5)) + 1;
    while (i < len) {
        *(s + i) = 'a' + rand() % 26;
        i = i + 1;
    }
    *(s + i) = '\0';
    return len; // end position
}

void gen_null(char *s) {
    *s = '\0';
}

int check_test_strcpy(char *s1, char *s2) {
    int i = 0;
    while (*(s2 + i) != '\0') {
        if (*(s2 + i) != *(s1 + i))
            return 0;
        i = i + 1;
    }
    return 1;
}

int test_strcpy(void) {
    char s1[MAX_STR], s2[MAX_STR];
    int i;
    // random test
    for (i = 0; i < TEST_COUNT; i++) {
        gen_str(s1);
        gen_str(s2);
        strcpy(s1, s2);
        // check
        if (!check_test_strcpy(s1, s2))
            return 0;
    }
    // null strings test
    gen_null(s1);
    strcpy(s1, s2); // 0 + aaa
    if (!check_test_strcpy(s1, s2))
        return 0;

    gen_null(s1);
    strcpy(s2, s1); // aaa + 0
    if (!check_test_strcpy(s2, s1))
        return 0;

    gen_null(s2);
    strcpy(s1, s2); // 0 + 0
    if (!check_test_strcpy(s1, s2))
        return 0;
    return 1;
}

int check_test_strcat(char *s1, char *s2, char *s3) {
    int i = 0, j = 0;
    while (*(s2 + i) != '\0') {
        if (*(s2 + i) != *(s1 + i))
            return 0;
        i = i + 1;
    }
    while (*(s3 + j) != '\0') {
        if (*(s1 + i + j) != *(s3 + j))
            return 0;
        j = j + 1;
    }
    return 1;
}

int test_strcat(void) {
    char s1[MAX_STR], s2[MAX_STR], s3[MAX_STR];
    int i;
    // random test
    for (i = 0; i < TEST_COUNT; i++) {
        gen_str(s1);
        strcpy(s3, s1); // tested correctly before
        gen_str(s2);
        strcat(s1, s2);
        // check
        if (!check_test_strcat(s1, s3, s2))
            return 0;
    }
    // null strings test
    gen_null(s1);
    strcpy(s3, s1);
    strcat(s1, s2); // 0 + aaa
    if (!check_test_strcat(s1, s3, s2))
        return 0;

    gen_null(s1);
    strcpy(s3, s2);
    strcat(s2, s1); // aaa + 0
    if (!check_test_strcat(s2, s3, s1))
        return 0;

    gen_null(s2);
    strcpy(s3, s1);
    strcat(s1, s2); // 0 + 0
    if (!check_test_strcat(s1, s3, s2))
        return 0;
    return 1;
}
int test_strcmp(void) {
    char s1[MAX_STR] = "aaaa", s2[MAX_STR] = "bbb"; 
    if(strcmp(s1, s2) == -1 && strcmp(s2, s1) == 1)
	return 1;
    return 0;   
}

int test_strlen(void) {
    char s1[MAX_STR];
    int i, result;
    // random test
    for (i = 0; i < TEST_COUNT; i++) {
        result = gen_str(s1);
        if (strlen(s1) != result)
            return 0;
    }
    // null test
    gen_null(s1);
    if (strlen(s1) != 0)
        return 0;
    return 1;
}