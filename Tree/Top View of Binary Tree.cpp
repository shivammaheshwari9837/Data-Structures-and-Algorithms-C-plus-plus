/*

Ques:- Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the 
tree is viewed from the top. For the given below tree

Time - O(n)
Space - O(n)

*/

#define pii pair<Node*,int> 

void topView(struct Node *root)
{
    //Your code here
    vector<int> left,right;
    int exLeft = 0,exRight = 0;
    
    queue<pii> q1;
    q1.push({root,0});
    
    while(!q1.empty())
    {
        int siz = q1.size();
        for(int i=0;i<siz;++i)
        {
            pii t1 = q1.front();
            Node *n1 = t1.first;
            q1.pop();
            
            if(t1.second < exLeft)
            {
                exLeft = t1.second;
                left.push_back(n1->data);
            }
            
            if(t1.second > exRight)
            {
                exRight = t1.second;
                right.push_back(n1->data);
            }
            
            if(n1->left != NULL)
            q1.push({n1->left,t1.second-1});
            
            if(n1->right != NULL)
            q1.push({n1->right,t1.second+1});
        }
    }
    
    for(int i=left.size()-1;i>=0;--i)
    cout<<left[i]<<" ";
    
    cout<<root->data<<" ";
    
    for(int i=0;i<right.size();++i)
    cout<<right[i]<<" ";
}
