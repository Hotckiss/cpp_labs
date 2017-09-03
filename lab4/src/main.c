#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/util.h"
#include"../include/mergesort.h"
int get(char *src) {
    int mul = 1, res = 0;
    if (*src == '-')
        mul = -1, *src++;
    while (*src != 0)
        res = 10 * res + *src - '0', *src++;
    return mul * res;
}
int main(int argc, char* argv[]) {
    int i, j;
    if(argc == 2) {
        printf("\n");
        return 0;
    }
    switch (*argv[1]) {
    case 'c': {
        char *mas = (char *)malloc(sizeof(char) * (argc - 2));
        for (i = 0; i < argc - 2; i++)
            move(&mas[i], argv[i + 2], sizeof(char));
        mergesort(mas, argc - 2, sizeof(char), compare_char);
        for (i = 0; i < argc - 2; i++)
            printf("%c ", mas[i]);
        printf("\n");
        free(mas);
        break;
    }
    case 'i': {
        int *mas = (int *)malloc(sizeof(int) * (argc - 2));
        for (i = 0; i < argc - 2; i++)
            mas[i] = get(argv[i + 2]);
        mergesort(mas, argc - 2, sizeof(int), compare_integers);
        for (i = 0; i < argc - 2; i++)
            printf("%i ", mas[i]);
        printf("\n");
        free(mas);
        break;
    }
    case 's': {
	
        char **mas = (char **)malloc(sizeof(char *) * (argc - 2));//, *str = (char *)malloc(sizeof(char) * mm * (argc - 2));
        for (i = 0; i < argc - 2; i++) {
            //j = 0;
            //while (argv[i + 2][j] != '\0')
            //    str[i*mm+j] = argv[i + 2][j], j++;
            
	    //str[i*mm+j] = '\0';
            mas[i] = argv[i + 2];
        }
       // for (i = 0; i < argc - 2; i++)
         //   printf("%s ", mas[i]);

       mergesort(mas, argc - 2, sizeof(char*) , compare_string);
        for (i = 0; i < argc - 2; i++) {
            //printf("%s ", mas[i]);
	    j = 0;
	    while(mas[i][j] != 0)
		printf("%c", mas[i][j]),j++;
	   printf(" ");
                 }
        printf("\n");
        //free(str); 
        free(mas);
        break;
    }
    }
    return 0;
}