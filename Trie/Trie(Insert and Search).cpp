/*

Ques:- Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use the 
TRIE data structure and search the given string A. If found print 1 else 0.

Concept:- 1.)We will implement Trie using a n-array tree
          2.)At every node of a tree, we make a)an array of size 26, pointing to child of Trie type, b)isEnd variable(for knowing is word ended in this node or not)
          
Insertion:-           
    Time - O(n * word_length + unique ones)
    Space - O(n*word_length)

Searching
  Time - O(word_length)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TrieNode  //Trie Node
{
    TrieNode* child[26]; //pointer pointing to child
    bool isEnd;  //knowing whether  stiring in trie end here or not
    
    TrieNode() 
    {
        for(int i=0;i<26;++i)  //initially making NULL every next character
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

void insert(TrieNode *root,string s)
{
    TrieNode *curr = root;
    
    for(int i=0;i<s.size();++i)
    {
        int index = s[i] - 'a';
        if(curr->child[index] == NULL) // for every character , checks if it not present as a child to further proceed, if not than insert it....
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true; //finally our words end here
}

bool search(TrieNode *root,string s)
{
    TrieNode *curr = root;
    
    for(int i=0;i<s.size();++i)
    {
        int index = s[i] - 'a';
        if(curr->child[index] == NULL) //if still our searching string not end, but Trie path end, than that string not present
        return false;
        
        curr = curr->child[index];
    }
    
    return curr->isEnd; //if string ends, but trie path from root does not end
}

void work()
{
    int n;
    cin>>n;
    
    vector<string> v1(n);
    
    for(int i=0;i<n;++i)
    {
        cin>>v1[i];
    }
    
    TrieNode *root = new TrieNode(); //initially , we make a simple root 
    
    for(int i=0;i<n;++i)
    {
        string temp = v1[i];
        
        insert(root,temp); //insrting the character
    }
    
    string tar;
    cin>>tar;
    
    cout<<search(root,tar);
    
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
