#include "candybar.h"

int main(){
    CandyBar cb;
    setCandyBar(&cb);
    showCandyBar(&cb);
    setCandyBar(cb);
    showCandyBar(cb);
}