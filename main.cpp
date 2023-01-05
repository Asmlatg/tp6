#include <iostream>
#include "sudoku.h"
using namespace std;

int main()
{
    sudoku su(4,9);
    su.solve(0,0);
    cout << su;
    return 0;
}
