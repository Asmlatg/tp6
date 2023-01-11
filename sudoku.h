#ifndef SUDOKU_H
#define SUDOKU_H
#include <cmath>
#include <array>
#include <iostream>
class sudoku
{
    public:
        sudoku(int m,int n);
        friend std::ostream& operator<<(std::ostream& flux, const sudoku game);
        bool verifierligne(int val,int _x,int _y);
        bool verifiercolonne(int _val, int _X, int _Y);
        bool verifierCE(int Val, int X, int Y);
        bool positionner(int entier,int X,int Y);
        bool solve();
        virtual ~sudoku();
    protected:

    private:
        int _n;
        std::array<std::array<int,9>, 9> _grid;

};


#endif // SUDOKU_H
