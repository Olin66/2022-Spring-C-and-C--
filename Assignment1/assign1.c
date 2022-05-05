#include <stdlib.h>
#include <math.h>

#include "assign1.h"
#include "assign1_mat.h"


matrix set_identity_matrix(matrix mat);


matrix copy_function_matrix(matrix mat_ori, matrix mat_res);


matrix set_identity_matrix(matrix mat) {
    for (int i = 0; i < mat.m_row; i++) {
        for (int j = 0; j < mat.m_col; j++) {
            if (i == j) set_by_index(mat, i, j, 1);
            else set_by_index(mat, i, j, 0);
        }
    }
    return mat;
}


matrix copy_function_matrix(matrix mat_ori, matrix mat_res) {
    for (int i = 0; i < mat_ori.m_row; i++) {
        for (int j = 0; j < mat_ori.m_col; j++) {
            int val = get_by_index(mat_ori, i, j);
            set_by_index(mat_res, i, j, val);
        }
    }
    return mat_res;
}


int quick_power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    long long partition_factor;
    partition_factor = quick_power(x, floor(n / 2)) % MODULO;
    if ((n & 1) == 1) {
        return ((partition_factor * partition_factor) % MODULO) * (x % MODULO) % MODULO;
    } else {
        return (partition_factor * partition_factor) % MODULO;
    }
}


int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res) {
    if (mat_a.m_row != mat_b.m_row || mat_a.m_row != mat_res.m_row ||
        mat_a.m_col != mat_b.m_col || mat_a.m_col != mat_res.m_col) {
        return 1;
    }
    for (int i = 0; i < mat_res.m_row; i++) {
        for (int j = 0; j < mat_res.m_col; j++) {
            int a_val = (long long) get_by_index(mat_a, i, j) % MODULO;
            int b_val = (long long) get_by_index(mat_b, i, j) % MODULO;
            int val = (a_val + b_val) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    }
    return 0;
}


// int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res) {//original method
//     if (mat_a.m_col != mat_b.m_row || mat_a.m_row != mat_res.m_row || mat_b.m_col != mat_res.m_col) {
//         return 1;
//     }
//     for (int i = 0; i < mat_a.m_row; i++) {
//         for (int j = 0; j < mat_b.m_col; j++) {
//             long long val = 0;
//             for (int k = 0; k < mat_a.m_col; k++) {
//                 long long a_val = (long long) get_by_index(mat_a, i, k) % MODULO;
//                 long long b_val = (long long) get_by_index(mat_b, k, j) % MODULO;
//                 val = (val + (a_val * b_val) % MODULO) % MODULO;
//             }
//             set_by_index(mat_res, i, j, (int) val);
//         }
//     }
//     return 0;
// }


int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res) {//advanced method
    if (mat_a.m_col != mat_b.m_row || mat_a.m_row != mat_res.m_row || mat_b.m_col != mat_res.m_col) {
        return 1;
    }
    matrix mat_temp = create_matrix_all_zero(mat_res.m_row, mat_res.m_col);
    for (int i = 0; i < mat_a.m_row; i++) {
        for (int k = 0; k < mat_a.m_col; k++) {
            long long a_val = (long long) get_by_index(mat_a, i, k);
            for (int j = 0; j < mat_b.m_col; j++) {
                long long b_val = (long long) get_by_index(mat_b, k, j);
                long long val = (long long) get_by_index(mat_temp, i, j);
                val = (val + (a_val * b_val) % MODULO) % MODULO;
                if (k == mat_a.m_col - 1) {
                    set_by_index(mat_res, i, j, (int) val);
                } else {
                    set_by_index(mat_temp, i, j, (int) val);
                }
            }
        }
    }
    delete_matrix(mat_temp);
    return 0;
}


int naive_matrix_exp(matrix mat_a, int exp, matrix mat_res) {
    if (mat_a.m_col != mat_a.m_row || mat_a.m_col != mat_res.m_col || mat_a.m_row != mat_res.m_row) {
        return 1;
    }
    if (exp == 1) {
        mat_res = copy_function_matrix(mat_a, mat_res);
        return 0;
    } else if (exp == 0) {
        mat_res = set_identity_matrix(mat_res);
        return 0;
    }
    matrix mat_b = copy_matrix(mat_a);
    for (int i = 0; i < exp - 1; i++) {
        matrix mat_temp = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
        matrix_multiplication(mat_b, mat_a, mat_temp);
        delete_matrix(mat_b);
        mat_b = copy_matrix(mat_temp);
        delete_matrix(mat_temp);
    }
    mat_res = copy_function_matrix(mat_b, mat_res);
    delete_matrix(mat_b);
    return 0;
}


int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res) {
    if (mat_a.m_col != mat_a.m_row || mat_a.m_col != mat_res.m_col || mat_a.m_row != mat_res.m_row) {
        return 1;
    }
    if (exp == 1) {
        mat_res = copy_function_matrix(mat_a, mat_res);
        return 0;
    } else if (exp == 0) {
        mat_res = set_identity_matrix(mat_res);
        return 0;
    }
    /**
     * mat_fac denotes the factor matrix.
     * mat_temp is a transient matrix.
     * mat_an is the final matrix of result.
     */
    matrix mat_fac = copy_matrix(mat_a);
    matrix mat_temp = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    matrix mat_an = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    mat_an = set_identity_matrix(mat_an);
    while (exp != 0) {
        if ((exp & 1) == 1) {
            matrix_multiplication(mat_an, mat_fac, mat_temp);
            delete_matrix(mat_an);
            mat_an = copy_matrix(mat_temp);
        }
        matrix_multiplication(mat_fac, mat_fac, mat_temp);
        delete_matrix(mat_fac);
        mat_fac = copy_matrix(mat_temp);
        // exp = floor(exp / 2); //c++无floor重载,double类型有精度损失
        exp>>=1; 
    }
    delete_matrix(mat_fac);
    delete_matrix(mat_temp);
    mat_res = copy_function_matrix(mat_an, mat_res);
    delete_matrix(mat_an);
    return 0;
}


int fast_cal_fib(long long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    }
    matrix mat = create_matrix_all_zero(2, 2);
    set_by_index(mat, 0, 0, 1);
    set_by_index(mat, 0, 1, 1);
    set_by_index(mat, 1, 0, 1);
    matrix mat_pow = create_matrix_all_zero(2, 2);
    fast_matrix_exp(mat, n - 1, mat_pow);
    matrix mat_ori = create_matrix_all_zero(2, 1);
    set_by_index(mat_ori, 0, 0, 1);
    matrix mat_res = create_matrix_all_zero(2, 1);
    matrix_multiplication(mat_pow, mat_ori, mat_res);
    delete_matrix(mat);
    delete_matrix(mat_pow);
    delete_matrix(mat_ori);
    int val = get_by_index(mat_res, 0, 0);
    delete_matrix(mat_res);
    return val;
}