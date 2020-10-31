/*

Ques:- Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of 
the binary tree and A is an ancestor of B. 

Concept:- 1)It is very simple,since I have to find maximum difference,so at every recursive call, I set my maximum and minimum element from root to all ancestor
          2)simply check the difference
          
Time - O(n)
Space - O(H)

*/

void helper(Node *root,int currMin,int currMax,int &ans)
{
    //base...
    if(root == NULL)
    return;
    
    ans = max(ans,currMin - root->data);
    ans = max(ans,currMax - root->data);
    
    currMax = max(currMax,root->data); //changing the max
    currMin = min(currMin,root->data); //checking/changing the minimum
    
    helper(root->left,currMin,currMax,ans);
    helper(root->right,currMin,currMax,ans);
}

int maxDiff(Node* root)
{
    // Your code here
    int currMax = root->data;
    int currMin = root->data;
    
    int ans = INT_MIN;
    
    helper(root->left,currMin,currMax,ans); //for left subtree 
    helper(root->right,currMin,currMax,ans); //for right subtree
    
    return ans;
}
