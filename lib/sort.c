#include <string.h>
#include "../include/sort.h"

<<<<<<< HEAD
long int cont_comp;
long int cont_swap;

void quick_sort(info * array, int left, int right)
=======
void quick_sort(info *array, int left, int right)
>>>>>>> d707c01e945c359c504d5c0a95a97482991513ec
{
    int pivo = left, j;
    char tempName[100];
    char tempPhone[20];

    for (int i = left + 1; i <= right; i++)
    {
<<<<<<< HEAD
        while ((strcmp(array[i].name, x) < 0) && (i < right)) {
            cont_comp++;
            i++;
        }

        while ((strcmp(array[j].name, x) > 0) && (j > left)) {
            cont_comp++;
            j--;
        }

        if (i <= j)
=======
        j = i;

        if (strcmp(array[j].name, array[pivo].name) < 0)
>>>>>>> d707c01e945c359c504d5c0a95a97482991513ec
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
<<<<<<< HEAD
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
=======
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

    for (i = 1; i <= size - 1; i++)
    {
        strcpy(tempName, array[i].name);
        strcpy(tempPhone, array[i].phone);

        j = i - 1;

        while (j >= 0 && strcmp(tempName, array[j].name) < 0)
        {
            strcpy(array[j + 1].name, array[j].name);
            strcpy(array[j + 1].phone, array[j].phone);
            j--;
        }

        strcpy(array[j + 1].name, tempName);
        strcpy(array[j + 1].phone, tempPhone);
    }
>>>>>>> d707c01e945c359c504d5c0a95a97482991513ec
}
