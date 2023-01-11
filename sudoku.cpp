#include "sudoku.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
sudoku::sudoku(int m, int n)
{
    _n=n;
    for (int a=0;a<_n;a++)
    {
        for (int b=0;b<_n;b++)
        {
            _grid[a][b]=0;
        }
    }
    int filled=0;
    switch (m)
    {
    case 1:
        while (filled!=40)
        {
            int i=rand()%_n;
            int j=rand()%_n;
            int valeur;
            valeur=(rand()%_n)+1;
            if (positionner(valeur,i,j))
            {
                _grid[i][j]=valeur;
                filled++;
            }
        }
    case 2:
        while (filled!=35)
        {
            int i=rand()%_n;
            int j=rand()%_n;
            int valeur= rand()%_n +1;
            if (positionner(valeur,i,j))
            {
                _grid[i][j]=valeur;
                filled++;
            }
        }
    case 3:
        while (filled!=30)
        {
            int i=rand()%_n;
            int j=rand()%_n;
            int valeur= rand()%_n +1;
            if (positionner(valeur,i,j))
            {
                _grid[i][j]=valeur;
                filled++;
            }
        }
    case 4:
        while (filled!=25)
        {
            int i=rand()%_n;
            int j=rand()%_n;
            int valeur= rand()%_n +1;
            if (positionner(valeur,i,j))
            {
                _grid[i][j]=valeur;
                filled++;
            }
        }
    case 5:
        while (filled!=20)
        {
            int i=rand()%_n;
            int j=rand()%_n;
            int valeur=(rand()%n)+1;
            if (positionner(valeur,i,j))
            {
                _grid[i][j]=valeur;
                filled++;
            }
        }
    }
}
bool sudoku::verifierligne(int val,int _x,int _y)
{
    bool ok=true;
    for (int j=0; j<=_n;j++)
    {
        if (_grid[_x][j]==val)
        {
            ok=false;
        }
    }
    return ok;
}
bool sudoku::verifiercolonne(int _val,int _X,int _Y)
{
    bool ok=true;
    for (int j=0; j<=_n;j++)
    {
        if (_grid[j][_Y]==_val)
        {
            ok=false;
        }
    }
    return ok;
}
bool sudoku::verifierCE(int Val, int X, int Y)
{
    int a;
    a=sqrt(_n);
    auto X0= (X/a)*a;
    auto Y0= (Y/a)*a;
    bool ok= true;
    for (int i=0; i<3 ; i++ )
    {
        for (int j=0; j<3;j++)
        {
            if (_grid[X0+i][Y0+j]==Val)
                ok=false;
        }
    }
    return ok;
}
bool sudoku::positionner(int entier,int X,int Y)
{
    if (verifierligne(entier,X,Y)& verifiercolonne(entier,X,Y) & verifierCE(entier,X,Y) & _grid[X][Y]==0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool sudoku::impasse(int x, int y)
{
  bool bl=true;
  for (int k=1;k<10;k++)
  {
    if (positionner(k,x,y))
    {
      bl=false;
    }
  }
  return bl;
}
bool sudoku::solve()
{
    int i,j;
    if (filled())
    {
        return true;
    }
    for (int k=1;k<=9;k++)
    {
        if (positionner(k,i,j))
        {
            _grid[i][j]=k;
            if (solve())
                return true;
            _grid[i][j]=0;
        }
    }
    return false;
}

sudoku::~sudoku()
{

}
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
  return flux;
}
