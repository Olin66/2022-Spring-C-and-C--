#pragma once

/**
 * @brief return product of 2 ~ 5 int numbers
 *
 * @return int product of numbers
 */
inline int product(int n1, int n2, int n3 = 1, int n4 = 1, int n5 = 1) {
    return n1 * n2 * n3 * n4 * n5;
}

/**
 * @brief return product of 2 ~ 5 doubles numbers
 *
 * @return double product of numbers
 */
inline double product(double n1, double n2, double n3 = 1, double n4 = 1, double n5 = 1) {
    return n1 * n2 * n3 * n4 * n5;
}