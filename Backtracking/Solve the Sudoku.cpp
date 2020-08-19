/*

Ques:- Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku. For simplicity you may assume that 
there will be only one unique solution.

Concept:- 1)Like all other Backtracking problems, we can solve Sudoku by one by one assigning numbers to empty cells. Before assigning a number,
          we check whether it is safe to assign. 
          2)We basically check that the same number is not present in the current row, current column and current 3 x 3 subgrid
          3)After checking for safety, we assign the number, and recursively check whether this assignment leads to a solution or not. If the assignment doesn’t 
          lead to a solution, then we try next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, we return false.
          
 Time - O(9*9*(9^n)*9) 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mat[10][10];

vector<pair<int,int> >vp1 = {{1,3} , {4,6} , {7,9}};

bool isSafe(int value,int row,int col) //check the validity
{
	for(int i=1;i<=9;++i) //row and column wise
	{
		if(mat[row][i] == value || mat[i][col] == value)
		return false;
	}
	
	if(row % 3 == 0)
	row = row/3-1;
	else
	row = row/3;
	
	if(col % 3 == 0)
	col = col/3-1;
	else
	col = col/3;
	
	pair<int,int> rowRan = vp1[row];
	pair<int,int> colRan = vp1[col];
	
	for(int i=rowRan.first;i<=rowRan.second;++i) //checking the 3*3 grid
	{
		for(int j=colRan.first;j<=colRan.second;++j)
		{
			if(mat[i][j] == value)
			return false;
		}
	}
	
	return true;
}

bool sudoku(int row,int col)
{
	
	if(col > 9) //if reach to end column
	{
		++row; //increase the row
		if(row > 9) //base condition
		return true;
    
		col = 1; //make current column back to 1
	}
	
	if(mat[row][col] == 0) //if empty cell
	{
		for(int j=1;j<=9;++j) //try all values from 1 to 9
		{
			if(isSafe(j,row,col))//if it is possible to fill the jth value
			{
				mat[row][col] = j; //fill it
				if(sudoku(row,col+1)) //check the further validity
				{
					return true;
				}
				mat[row][col] = 0; //if a temporary solution not possible, backtrack all the filled values to an empty cells
			}
		}
		return false;
	}
	else if(sudoku(row,col+1)) //if some value is initially filled
	return true; 
	else
	return false;
}

void work()
{
	for(int i=1;i<=9;++i)
	for(int j=1;j<=9;++j)
	cin>>mat[i][j];
	
	bool ans = sudoku(1,1);
	
	if(ans)
	{
		for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
		cout<<mat[i][j]<<" ";
	}
	else
	cout<<-1;
	
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}
