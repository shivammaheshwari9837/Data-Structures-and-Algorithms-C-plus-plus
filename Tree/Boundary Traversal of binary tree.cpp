/*

Ques:- Write a function to print Boundary Traversal of a binary tree. Boundary Traversal of a binary tree here means that you have to return boundary nodes of the 
       binary tree Anti-Clockwise starting from the root.
      
Concept:- 1)here first we traverse the left boundary(except the leaves)[top-down manner]
          2)Than we recurr towards the leaves
          3)than, travel through the right boundary(except the leaves)[in bottom-up fashion]
          
Time - O(n)
Space - O(height)

*/

void leftBound(Node *root,vector<int> &ans) //towards the left boundary
{
    //base...
    if(root == NULL)
    return;
    
    
    if(root->left) //if left if there,we traverse
    {
        ans.push_back(root->data);
        leftBound(root->left,ans);
    }
    else if(root->right) //else if right exits
    {
        ans.push_back(root->data);
        leftBound(root->right,ans); //traverse in the right direction
    }
    
    //else leaves found.....,do nothing
}

void rightBound(Node *root,vector<int> &ans)
{
    if(root == NULL)
    return;
    
    if(root->right)
    {
        rightBound(root->right,ans);
        ans.push_back(root->data); //here we put the data in bottom-up fashion
    }
    else if(root->left)
    {
        rightBound(root->left,ans);
        ans.push_back(root->data); 
    }
    //else leaves found.....,do nothing
    
}

void leaves(Node *root,vector<int> &ans) //simple for storing the leavses
{
    //base..
    if(root == NULL)
    return;
    
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    leaves(root->left,ans);
    leaves(root->right,ans);
}

vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int> ans;
     ans.push_back(root->data);
     
     if(root->left == NULL && root->right == NULL) 
     return ans;
     
     leftBound(root->left,ans);
     leaves(root,ans);
     rightBound(root->right,ans);
     
     return ans;
     
}
