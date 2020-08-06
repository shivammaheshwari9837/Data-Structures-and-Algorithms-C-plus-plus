/*

Ques :- Given a BST, modify it so that all greater values in the given BST are added to every node.

Concept:- 1.) try to do traversal in format  --------->  (right,root,left), and hope this wiil            help

*/

void helper(Node *root,int *total)
{
    if(root == NULL)
    return;
    
    helper(root->right,total); // towards the right subtree
    
    *total+=(root->data);
    root->data = *total; // than root 
    
    helper(root->left,total); //towards the left subtree
    
    return;
}

Node* modify(Node *root)
{
    // Your code here
    int total = 0; // a pass by reference value for storing the current sum
    
    helper(root,&total);
    
    return root;
}
