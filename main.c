#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/csv.h"
#include "include/sort.h"
#include "include/benchmark.h"

#define DATA1_SIZE 100
#define DATA2_SIZE 500
#define DATA3_SIZE 1000

#define ITER 100

extern long int cont_comp;
extern long int cont_swap;

// context == 0 -> algorithm menu
// context == 1 -> data menu
void options(size_t context) {
    if(!context) {
        puts("Bem-vindo a análise de perfomance temporal de algoritmos de odernação.");
        puts("\nEscolha um algoritmo ou uma das opções abaixo:");
        puts("  1 - Quick Sort");
        puts("  2 - Insertion Sort");
        puts("  3 - Limpar a tela");
        puts("  0 - Sair");
    } else {
        puts("--------------------------------------");
        puts("Escolha o tamanho do vetor de dados:");
        puts("  1 - 100 registros");
        puts("  2 - 500 registros");
        puts("  3 - 1000 registros");
        puts("  0 - Voltar");
    }
    printf("\n> ");
}

int main(void)
{
    size_t opt_menu1, opt_menu2;
    timeval start, end, result;
    info * data;
    do {
        options(0);
        scanf("%zu", &opt_menu1);
        switch(opt_menu1) {
            case 1:
                do {
                    puts("\nQuick Sort");
                    puts("\n* O algoritmo é executado *100 vezes*, então o tempo médio gasto deverá ser calculado levando isto em conta.");
                    options(1);
                    scanf("%zu", &opt_menu2);
                    cont_comp = 0;
                    cont_swap = 0;
                    switch(opt_menu2) {
                        case 1:
                            data = (info *)malloc(DATA1_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_100.csv", data, DATA1_SIZE);
                                quick_sort(data, 0, DATA1_SIZE - 1);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 2:
                            data = (info *)malloc(DATA2_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_500.csv", data, DATA2_SIZE);
                                quick_sort(data, 0, DATA2_SIZE - 1);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 3:
                            data = (info *)malloc(DATA3_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_1000.csv", data, DATA3_SIZE);
                                quick_sort(data, 0, DATA3_SIZE - 1);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            puts("Opção inválida!");
                            break;
                    }
                } while(opt_menu2 != 0);
                break;
            case 2:
                do {
                    puts("\n* O algoritmo é executado *100 vezes*, então o tempo médio gasto deverá ser calculado levando isto em conta.");
                    puts("\nInsertion Sort");
                    options(1);
                    scanf("%zu", &opt_menu2);
                    cont_comp = 0;
                    cont_swap = 0;
                    switch(opt_menu2) {
                        case 1:
                            data = (info *)malloc(DATA1_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_100.csv", data, DATA1_SIZE);
                                insertion_sort(data, DATA1_SIZE);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 2:
                            data = (info *)malloc(DATA2_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_500.csv", data, DATA2_SIZE);
                                insertion_sort(data, DATA2_SIZE);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 3:
                            data = (info *)malloc(DATA3_SIZE * sizeof(info));
                            puts("\nRealizando benchmark...");
                            gettimeofday(&start);
                            for(int i = 0; i < ITER; i++) {
                                populate_array("data/data_1000.csv", data, DATA3_SIZE);
                                insertion_sort(data, DATA3_SIZE);
                            }
                            gettimeofday(&end);
                            result = timersub(end, start);
                            printf("\nTempo de execução: %ld.%06ld segundos\n", result.tv_sec, result.tv_usec);
                            printf("Número de comparações: %ld\n", cont_comp);
                            printf("Número de trocas: %ld\n", cont_swap);
                            free(data);
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            puts("Opção inválida!");
                            break;
                    }
                } while(opt_menu2 != 0);
                break;
            case 3:
                system("cls");
                break;
            case 0:
                return 0;
            default:
                puts("Opção inválida!");
                break;
        }
    } while(1);

    return 0;
}
