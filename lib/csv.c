#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/csv.h"

void populate_array(char *filepath, info *array, size_t size)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        printf("could not open file %s\n", filepath);
        exit(404);
    }

    char buffer[256];
    size_t column;

    for (size_t row = 0; row < size; row++)
    {
        fgets(buffer, 200, file);
        char *value = strtok(buffer, ",");
        column = 0;
        while (value)
        {
            if (column == 0)
            {
                strcpy(array[row].name, value);
            }
            else
            {
                strcpy(array[row].phone, value);
                array[row].phone[strlen(array[row].phone) - 1] = '\0';
            }
            value = strtok(NULL, ",");
            column++;
        }
    }

    fclose(file);
}

void quickSort(info *array, int left, int right)
{
    int i, j;
    char *x;
    char tempName[100];
    char tempPhone[100];

    i = left;
    j = right;
    x = array[(left + right) / 2].name;

    do
    {
        while ((strcmp(array[i].name, x) < 0) && (i < right))
        {
            i++;
        }
        while ((strcmp(array[j].name, x) > 0) && (j > left))
        {
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
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
    {
        quickSort(array, left, j);
    }
    if (i < right)
    {
        quickSort(array, i, right);
    }
}

// void insert(info *array, int count)
// {

//     int i, b;
//     info t;

//     for (i = 1; i < count; ++i)
//     {
//         t = array[i];
//         for (b = i - 1; (b >= 0) && (t.name < array[b].name); b--)
//             array[b + 1] = array[b];
//         array[b + 1] = t;
//         // array = t;
//     }
// }