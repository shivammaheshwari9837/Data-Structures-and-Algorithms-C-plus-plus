/*

Ques:- Given a binary matrix your task is to complete the function printMat which prints all unique rows of the given matrix. 
The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix.

Concept:- 1.)It is just similar to Trie(ie. think in a way while inserting in a trie, can we print simultaneously too)

Time - O(n * m)
Space:- O(n*m) [Trie building]

*/


struct Trie  //Simple Trie Structure
{
    Trie *child[2];
    
    Trie()
    {
        for(int i=0;i<=1;++i)
        child[i] = NULL;
    }
};

void insert(Trie* root,int row_num,int no_col,int mat[][MAX]) //insertion in a try
{
    Trie *curr = root;
    vector<int> temp; 
    bool isNew = false; //bool variable(if any new node is inserted , it will print the row too)
    for(int j=0;j<no_col;++j)
    {
        int val = mat[row_num][j];
        temp.push_back(val);
        if(curr->child[val] == NULL)
        {
            curr->child[val] = new Trie();
            isNew = true;
        }
        curr = curr->child[val];
    }
    
    if(isNew)    //bool variable(if any new node is inserted , it will print the row too)
    {
        for(int i=0;i<temp.size();++i)
        cout<<temp[i]<<" ";
        
        cout<<"$";
    }
}



void printMat(int M[MAX][MAX],int row,int col)
{
//Your code here
    Trie *root = new Trie();
    
    for(int i=0;i<row;++i)
    {
        insert(root,i,col,M);
    }
}
