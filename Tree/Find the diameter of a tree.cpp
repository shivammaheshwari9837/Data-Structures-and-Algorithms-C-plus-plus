/*

Ques :- Find the diameter of a binarytree

*/

int ans;

int findDia(Node *root)
{
    if(root == NULL)
    return 0;
    
    int l1 = findDia(root->left);
    
    int l2 = findDia(root->right);
    
    ans = max(ans,l1 + l2 + 1);// finding the diameter...
    
    return (max(l1,l2) + 1);// finding the largest height...
    
}

int diameter(Node* node) {
    // Your code here
    ans = 0;
    int v = findDia(node);
    
    return ans;
}
