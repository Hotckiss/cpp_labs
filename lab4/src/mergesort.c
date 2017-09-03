#include<stdio.h>
#include<stdlib.h>
void move(void *destination, const void *source, size_t len) {
    unsigned int i;
    char *to = (char *)destination, *from = (char *)source;
    for (i = 0; i < len; i++)
        *to = *from, *to++, *from++;
}
int mergesort(void* base, size_t num, size_t size, int(*compar)(const void*, const void*)) {
      if (num > 1) {
        unsigned int new_1 = num / 2, new_2 = (num % 2 == 0) ? num / 2 : num / 2 + 1, i = 0, j = 0;
        mergesort((char *)base, new_1, size, compar);
        mergesort((char*)((char *)base + new_1 * size), new_2, size, compar);
        char *buf_box = (char *)malloc(size * num), *buf = buf_box;
        while (i < new_1  && j < new_2) {
            if (compar((char*)((char *)base + i * size), (char*)((char *)base + (j + new_1) * size)) < 0)
                move(buf, (char*)((char *)base + i * size), size), i++;
            else
                move(buf, (char*)((char *)base + (j + new_1) * size), size), j++;
            buf = buf + size;
        }
        while (i < new_1)
            move(buf, (char*)((char *)base + i * size), size), i++, buf = buf + size;
        while (j < new_2)
            move(buf, (char*)((char *)base + (j + new_1) * size), size), j++, buf = buf + size;
        for (i = 0; i < num; i++)
            move((char*)((char *)base + i * size), &(*(buf_box + i * size)), size);
        free(buf_box);
    }                
    return 0;
}

