/*

Ques:- Given a binary tree and two node values your task is to find the minimum distance between them.

Concept:- 1)Here we first try to find out the LCA of a tree
          2)With LCA ,than we will calculate the distance between nodes
          
Time - O(n)
Space - O(height)
*/

Node *lca(Node *root,int &a,int &b) //basic LCA of two nodes
{
    if(root == NULL)
    return NULL;
    
    if(root->data == a || root->data == b)
    return root;
    
    Node *p = lca(root->left,a,b);
    Node *q = lca(root->right,a,b);
    
    if(p == NULL && q == NULL)
    return NULL;
    else if(p != NULL && q != NULL)
    return root;
    else if(p != NULL)
    return p;
    else
    return q;
    
}

int dis(Node *root,int ele,int he)
{
    //base...
    if(root == NULL) //if reaches to last,not found
    return -1;
    if(root->data == ele) //if found,return current height
    return he;
    
    int a = dis(root->left,ele,he+1); //left subtree
    int b = dis(root->right,ele,he+1); //right subtree
    
    return max(a,b); //since only one path contains the target element, thus can be find 
}
   
int findDist(Node* root, int a, int b) {
    // Your code here
    
    Node *point = lca(root,a,b);
    // cout<<point->data<<"\n"; 
    
    int d1 = 0,d2 = 0;
    
    d1 = dis(point,a,0);
    
    d2 = dis(point,b,0);
    
    return d1+d2;
}
