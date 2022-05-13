#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assign1.c"
#include "assign1_mat.c"

int main(){
    int row = 10000;
    int col = 10000;
    matrix m = create_matrix_all_zero(row, col);
    matrix m2 = create_matrix_all_zero(row, col);
    matrix m_res = create_matrix_all_zero(row, col);
    int MAX = 2147483647;
    srand((unsigned int)time(0));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int val = rand();
            val = val % (MAX - 1);
            set_by_index(m, i, j, val);
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int val = rand();
            val = val % (MAX - 1);
            set_by_index(m2, i, j, val);
        }
    }
    clock_t start, finish;
    double time;
    start = clock();
    matrix_multiplication(m, m2, m_res);
    finish = clock();
    time = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("Time cost of original method = %lf\n", time);
    // printf("Time cost of advanced method = %lf\n", time);
}