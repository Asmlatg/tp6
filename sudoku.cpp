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
    auto sqL= X-X%a+1;
    auto sqC= Y-Y%a+1;
    bool ok= true;
    for (int i= sqL; i<= sqL+a-1 ; i++ )
    {
        for (int j=sqC; j<=sqC+a-1;j++)
        {
            if (_grid[i][j]==Val)
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
bool sudoku::solve(int ligne, int col){
    if(col == 9)
    {
      return true;
    }
    if(_grid[ligne][col] != 0)
    {
        if(ligne== 8)
        {
            return solve(0,col+1);
        }
        else
        {
            return solve(ligne+1,col);
        }
    }
    for(int i=1; i<=9; i++)
    {
      _grid[ligne][col] = i;
      if(positionner(i,ligne,col))
      {
        if(ligne == 8)
        {
          if(solve(0,col+1))
            return true;
        }
        else
        {
          if(solve(ligne+1,col))
            return true;
        }
      }
    }
    _grid[ligne][col] = 0;
    return false;
}
sudoku::~sudoku()
{

}
int main()
{
    sudoku su(5,9);
    su.solve(0,0);
    cout << su;
    return 0;
}
