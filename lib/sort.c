#include <string.h>
#include "../include/sort.h"

void quick_sort(info *array, int left, int right)
{
    int pivo = left, j;
    char tempName[100];
    char tempPhone[20];

    for (int i = left + 1; i <= right; i++)
    {
        j = i;

        if (strcmp(array[j].name, array[pivo].name) < 0)
        {
            strcpy(tempName, array[j].name);
            strcpy(tempPhone, array[j].phone);

            while (j > pivo)
            {
                strcpy(array[j].name, array[j - 1].name);
                strcpy(array[j].phone, array[j - 1].phone);
                j--;
            }

            strcpy(array[j].name, tempName);
            strcpy(array[j].phone, tempPhone);
            pivo++;
        }
    }

    if (pivo - 1 >= left)
        quick_sort(array, left, pivo - 1);

    if (pivo + 1 <= right)
        quick_sort(array, pivo + 1, right);
}

void insertion_sort(info *array, int size)
{
    int i, j;
    char tempName[100];
    char tempPhone[20];

    for (i = 1; i < size; i++)
    {
        for (j = i; j > 0 && strcmp(array[j].name, array[j - 1].name) < 0; j--)
        {
            strcpy(tempName, array[j - 1].name);
            strcpy(array[j - 1].name, array[j].name);
            strcpy(array[j].name, tempName);

            strcpy(tempPhone, array[j - 1].phone);
            strcpy(array[j - 1].phone, array[j].phone);
            strcpy(array[j].phone, tempPhone);
        }
    }
}