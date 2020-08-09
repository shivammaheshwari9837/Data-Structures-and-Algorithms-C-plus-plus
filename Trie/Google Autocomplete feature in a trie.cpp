/*

Ques:- Given a prefix,print all suggestions of some queries q like a search engine(means in ascendin order). Assume that data is been preloaded in a trie

Concept:- 1.)First visit till the last prefix node
          2.) than do preorder traversal
          3.)Here preorder traversal can be achieved using child array for getting in sorted order

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Trie
{
	Trie* child[26];
	int wordEnd ;
	
	Trie()
	{
		for(int i=0;i<26;++i)
		{
			child[i] = NULL;
		}
		wordEnd = 0;
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
	
	++(curr->wordEnd);
	
}

void printWords(Trie *root,string temp)
{
	
	if(root->wordEnd > 0)
	{
		for(int i=0;i<(root->wordEnd);++i)
		cout<<temp<<" ";
	}
	
	for(int i=0;i<26;++i)
	{
		if(root->child[i] != NULL)
		{
			temp.push_back(i + 97);
			printWords(root->child[i],temp);
		}
	}
	
	
}

void autoComplete(Trie *root,string tar)
{
	Trie *curr = root;
	
	for(int i=0;i<tar.size();++i)
	{
		int index = tar[i] - 'a';
		
		if(curr->child[index] == NULL)
		{
			cout<<"Wrong Query \n";
			return;
		}
		curr = curr->child[index];
	}
	
	printWords(curr,tar);
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
	
	int query;
	cin>>query;
	
	for(int i=0;i<query;++i)
	{
		string s;
		cin>>s;
		
		autoComplete(root,s);
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
