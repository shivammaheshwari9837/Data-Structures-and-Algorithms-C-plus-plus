/*

Ques:- A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. Given an undirected graph  the task is to check if a 
Hamiltonian path is present in it or not.

Method 1:- a)Make a boolean matrix between all possible edges given
           b)Than check all permutations of from 1 to n, and find valid one

Time - O(!n)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool gra[15][15];

bool check(int n)
{
    vector<int> temp;
    
    for(int i=1;i<=n;++i)
    temp.push_back(i);
    
    do
    {
        bool valid = true;
        for(int i=0;i<temp.size()-1;++i)
        {
            if(gra[temp[i]][temp[i+1]] != true)
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
          return true;
		    }
    }while(next_permutation(temp.begin(),temp.end())); //finding the all permutations and check each of them
    
    return false;
}

void work()
{
    int n,m,x,y;
    cin>>n>>m;
    
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    gra[i][j] = false;
    
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        gra[x][y] = true;
        gra[y][x] = true;
    }
    
    bool ans = check(n);
    
    if(ans)
    cout<<1;
    else
    cout<<0;
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

/*

Method 2:- 

*/
