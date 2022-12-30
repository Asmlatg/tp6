#ifndef SUDOKU_H
#define SUDOKU_H
#include <cmath>
#include <array>
#include <iostream>
class sudoku
{
    public:
        sudoku(int m,int n);
        friend std::ostream & operator<<(std::ostream &flux, sudoku grid);
        bool verifierligne(int val,int _x,int _y);
        bool verifiercolonne(int _val, int _X, int _Y);
        bool verifierCE(int Val, int X, int Y);
        bool positionner(int entier,int X,int Y);
        bool solve(int ligne,int col);
        virtual ~sudoku();
    protected:

    private:
        int _n;
        std::array<std::array<int,9>, 9> _grid;

};
std::ostream& operator<<(std::ostream& flux, const sudoku game)
{
    int c;
    c=sqrt(game._n);
    for (int a=0; a<=(game._n)-1; a++)
    {
        int d(a);
        if (d%c==0)
        {
            flux << " --------------------------" << std::endl;
        }
        for (int b=0; b<=game._n-1 ; b++)
        {
            int e(b);
            if (e%c==0 and e!=0)
            {
                flux <<"|";
            }

            flux << " " << game._grid[a][b] << " ";

            if (e==game._n-1)
            {
                flux<< "|" << std::endl;
            }
        }
    }
}

#endif // SUDOKU_H
