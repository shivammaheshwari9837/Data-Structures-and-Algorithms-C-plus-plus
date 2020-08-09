/*

Ques:- Given n number of string to be inserted.Given sequence of m strings that need to be deleted from Trie if found else not

Concept:- For Deletion:-
                      1.)Simple we decreament the isEnd variable for the current node
                      2.)Must see insertion before understanding.

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Trie
{
	Trie* child[26];
	int isEnd ; // for counting that how many words end at that particular node at trie
	
	Trie()
	{
		for(int i=0;i<26;++i)
		{
			child[i] = NULL;
		}
		isEnd = 0;
	}
};

void insert(string tar,Trie *root)
{
	Trie *curr = root;
	
	for(int i=0;i<tar.size();++i)
	{
		int index = tar[i] - 'a';
		if(curr->child[index] == NULL)
		{
			curr->child[index] = new Trie();
		}
		curr = curr->child[index];
	}
	
	++(curr->isEnd);
}

bool deletion(string str,Trie *root)
{
	Trie *curr = root;
	
	for(int i=0;i<str.size();++i)
	{
		int index = str[i] - 'a';
		
		if(curr->child[index] == NULL)  // for checking that the word to be deleted is longer than trie path
		return false;
		
		curr = curr->child[index];
	}
	
	if(curr->isEnd > 0)  // is there is a word left at the current trie node
	{
		--(curr->isEnd); // reducing count as deleted single word here
		return true;
	}
	else
	return false;
}

void work()
{
    int n;
    cin>>n;
    
    vector<string> v1(n);
    
    for(int i=0;i<n;++i)
    cin>>v1[i];
    
    Trie *root = new Trie();
    
    for(int i=0;i<n;++i)
    {
    	insert(v1[i],root);
	}
	
	int no_del; //no of nodes to be deleted
	cin>>no_del;
	
	for(int i=0;i<no_del;++i)
	{
		string s;
		cin>>s;
		bool check = deletion(s,root);
		
		if(check)
		cout<<"Deleted";
		else
		cout<<"Not Found";
		
		cout<<"\n";
	}
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
