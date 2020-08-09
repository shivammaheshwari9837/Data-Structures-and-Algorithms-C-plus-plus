/*

Ques:- Count the number of strings present in an array of strings with given prefix

Concept:- 1.) we take an differnt type of variable(calles as no_prefix) which will incrented whenever a particular node is visited again in a trie


*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Trie
{
	Trie* child[26];
	int no_prefix ; // speacial pointer 
	
	Trie()
	{
		for(int i=0;i<26;++i)
		{
			child[i] = NULL;
		}
		no_prefix = 0;
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
		++(curr->no_prefix); //every time we encounter the alphabet, just increament the value
		// cout<<curr->no_prefix<<" ";
	}
	
}

int prefixCount(string str,Trie *root)
{
	Trie *curr = root;
	
	for(int i=0;i<str.size();++i)
	{
		int index = str[i] - 'a';
		curr = curr->child[index];
	}
	
	return (curr->no_prefix); //simply return the count
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
	
	int number;
	cin>>number;
	
	for(int i=0;i<number;++i)
	{
		string s;
		cin>>s;
		int ans = prefixCount(s,root);
		cout<<ans<<"\n";
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
