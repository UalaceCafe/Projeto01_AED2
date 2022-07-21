#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/csv.h"

void populate_array(char * filepath, info * array, size_t size) {
    FILE * file = fopen(filepath, "r");
    if(!file) {
        printf("could not open file %s\n", filepath);
        exit(404);
    }

    char buffer[256];
    size_t column;

    for(size_t row = 0; row < size; row++) {
        fgets(buffer, 200, file);
        char * value = strtok(buffer, ",");
        column = 0;
        while(value) {
            if(column == 0) {
                strcpy(array[row].name, value);
            } else {
                strcpy(array[row].phone, value);
                array[row].phone[strlen(array[row].phone)-1] = '\0';
            }
            value = strtok(NULL, ",");
            column++;
        }
    }

    fclose(file);
}
