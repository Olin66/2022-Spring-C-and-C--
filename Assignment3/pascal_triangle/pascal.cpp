#include "pascal.h"

int pascal(int row, int column){
    if (column < 0 || row < 0 || column > row)
        return 0;
    if (row == 0 && column == 0)
        return 1;
    return pascal(row-1, column) + pascal(row-1, column-1);
}