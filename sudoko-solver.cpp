#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define N 9


bool is_safe(int grid[][N], int row, int col, int num)
    {
        for(int i=col; i<N; i++)
        {
            if(grid[row][i]==num) return false;
        }
        for(int i=col; i>=0; i--)
        {
            if(grid[row][i]==num) return false;
        }
        for(int i=row; i<N;i++)
        {
            if(grid[i][col]==num) return false;
        }
        for(int i=row; i>=0;i--)
        {
            if(grid[i][col]==num) return false;
        }
        
        int x=row/3;   int y=col/3;
         x=x*3;             y= y*3;
        for(int i=x; i<x+3; i++)
        {
            for(int j=y; j<y+3; j++)
            {
                if(grid[i][j]==num) return false;
            }
        }
        
        return true;
        
    }

bool sudoko_solver(int grid[][N], int row, int col)
{
    if(col==N)
        {
            
             return sudoko_solver(grid,row+1,0) ;
              
        }
        if(row==N)
        {
            return true;
        }
        if(grid[row][col]>0)
        {
             return sudoko_solver(grid, row, col+1);
             
        }
        
        for(int num=1; num<=9; num++)
        {
            if(is_safe(grid,row,col,num))
            { 
                grid[row][col]=num;
                if(sudoko_solver(grid,row,col+1))  return true;
                else grid[row][col]=0;
            }
        }
        
        return false;

}
int main()
{
    ofstream fileinput;
    fileinput.open("input.txt",ios::out);
    int grid[N][N];

    cout<<"enter the numbers row wise:"<<endl;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
            fileinput<<grid[i][j];
            fileinput<<" ";
        }
        fileinput<<endl;
    }

    fileinput.close();

    bool temp=sudoko_solver(grid,0,0);

    ofstream fileout;
    fileout.open("output.txt");

    if(temp)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                fileout<<grid[i][j]<<" ";
            }
            fileout<<endl;
        }
    }
    else 
    {
        fileout<<"this sudoko is not solvable"<<endl;
    }

    fileout.close();

    return 0;

}