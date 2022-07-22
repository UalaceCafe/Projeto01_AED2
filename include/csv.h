#include <stdint.h>

typedef struct
{
    char name[100];
    char phone[20];
} info;

void populate_array(char *filepath, info *array, size_t size);
void quickSort(info *array, int left, int right);
void insertionSort(info *array, int size);
