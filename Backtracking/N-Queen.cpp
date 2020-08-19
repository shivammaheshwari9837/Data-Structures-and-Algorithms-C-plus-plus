/*

Ques:- Print the solution of N-Queen(only column number)
        Example:
        Input
        2
        1
        4
        Output:
        [1 ]
        [2 4 1 3 ] [3 1 4 2 ]
        
Concept:- 1)Here we will use Backtracking while checking the valid conditions too(ie. if Queen is placed or not)

Time - O(n*(n^n) )  [Exponential]

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(int row,int col,vector<int> loca) // O(n) checking the validity,take pen and paper for sure
{

/*

a new queen can be placed if any of the conditions must not true
    a)must not be placed diagonally to some previuos placed queens
    b)must not in the same column to some previous placed queen
    c)we will check above two conditions for every previous placed queen 

*/

	for(int i=0;i<loca.size();++i) //this is above described work
	{
		int prevR = i+1;
		int prevC = loca[i];
		
		int diff1 = abs(row - prevR); //for diagonals
		int diff2 = abs(col - prevC); //for diagonals
		
		if(diff1 == diff2 || col == prevC)
		return false;
	}
	
	return true;
}


void nQueen(int &n,int row,vector<int> loca,bool &isPossible)
{
	if(row > n)  //base condition
	{
	    isPossible = true; //a solution exist..
		cout<<"[";
		for(int i=0;i<loca.size();++i)
		cout<<loca[i]<<" ";
		
		cout<<"] ";
		return;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(isSafe(row,i,loca)) //checking can queen be placed in ith column of current row
		{
			loca.push_back(i); //push it 
			nQueen(n,row+1,loca,isPossible); //do further calls
			loca.pop_back(); //remove it, ie. becktrack it for future calls
		}
		
	}
	return;
}

void work()
{
	int n;
	cin>>n;
	
	vector<int> loca;
	
	bool isPossible = false;
	nQueen(n,1,loca,isPossible); //(given n, row number , empty vector , a variable that is passed by reference to see whether a solution exist or not)
	
	if(!isPossible) // a variable that is passed by reference to see whether a solution exist or not
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
