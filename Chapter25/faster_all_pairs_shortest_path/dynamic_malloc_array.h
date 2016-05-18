#ifndef _DYNAMIC_MALLOC_ARRAY
#define _DYNAMIC_MALLOC_ARRAY
#include"stdio.h"
#include"stdlib.h"
int** dynamic_malloc_array(int m,int n);        //dynamid malloc two dimension array and return pointer of the array
void free_array(int** pointer);
#endif
