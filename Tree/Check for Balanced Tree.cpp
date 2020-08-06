/*

Ques :- Check for Balanced Tree(in O(n) )

*/

bool ans;// Global variable to store the final answer

int check(Node *root)
{
    if(root == NULL)
    return 0;
    
    int h1 = check(root->left); // finding the height of left subtree
    
    int h2 = check(root->right); // finding the height of right subtree
    
    if(abs(h1 - h2)>1)
    ans=false;
    
    return (max(h1,h2) + 1 );
}

bool isBalanced(Node *root)
{
    ans = true;
    int temp = check(root);
    return ans;
}

