#ifndef __MERGESORT_H__
#define __MERGESORT_H__
int mergesort(void* base, size_t num, size_t size, int(*compar)(const void*, const void*));
void move(void *destination, const void *source, size_t len);
#endif


