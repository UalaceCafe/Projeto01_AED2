#include <string.h>
#include "../include/sort.h"

long int cont_comp;
long int cont_swap;

void quick_sort(info * array, int left, int right)
{
    int i, j;
    char * x;
    char tempName[100];
    char tempPhone[20];

    i = left;
    j = right;
    x = array[(left + right) / 2].name;

    do
    {
        while ((strcmp(array[i].name, x) < 0) && (i < right)) {
            cont_comp++;
            i++;
        }

        while ((strcmp(array[j].name, x) > 0) && (j > left)) {
            cont_comp++;
            j--;
        }

        if (i <= j)
        {
            strcpy(tempName, array[i].name);
            strcpy(tempPhone, array[i].phone);
            strcpy(array[i].name, array[j].name);
            strcpy(array[i].phone, array[j].phone);
            strcpy(array[j].name, tempName);
            strcpy(array[j].phone, tempPhone);
            cont_swap += 2;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        quick_sort(array, left, j);

    if (i < right)
        quick_sort(array, i, right);
}

void insertion_sort(info * array, int size)
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

            cont_comp++;
            cont_swap += 2;
        }
    }
}
