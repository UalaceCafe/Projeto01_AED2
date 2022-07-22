#ifndef CSV_H

#define CSV_H

#include <stddef.h>

typedef struct {
    char name[100];
    char phone[20];
} info;

void populate_array(char * filepath, info * array, size_t size);

#endif
