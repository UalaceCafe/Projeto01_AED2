#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/csv.h"

#define DATA1_SIZE 100
#define DATA2_SIZE 500
#define DATA3_SIZE 1000

int main(void)
{
    info contacts[DATA1_SIZE] = {};
    populate_array("data/data_100.csv", contacts, DATA1_SIZE);

    quickSort(contacts, 0, DATA1_SIZE - 1);

    insertionSort(contacts, DATA1_SIZE);

    for (int i = 0; i < DATA1_SIZE; i++)
    {
        printf("Name: %s | Phone: %s\n", contacts[i].name, contacts[i].phone);
    }

    return 0;
}