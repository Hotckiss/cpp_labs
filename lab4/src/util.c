#include<stdio.h>
int compare_integers(const void* elem_1, const void* elem_2) {
    return *(int*)elem_1 - *(int*)elem_2;
}
int compare_char(const void* elem_1, const void* elem_2) {
    return *(char*)elem_1 - *(char*)elem_2;
}
int compare_string(const void* elem_1, const void* elem_2) {
    int i = 0;
    char **str_1 = (char**)elem_1, **str_2 = (char**)elem_2;
    while (*(*str_1+i) != 0 && *(*str_2+i) != 0 && *(*str_1+i) == *(*str_2+i))
	i++;
    return *(*str_1+i) -  *(*str_2+i);
}
