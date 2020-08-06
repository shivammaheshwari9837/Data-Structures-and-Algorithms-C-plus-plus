/*

Ques :-  Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.

Concept:- 1.) instead of doing ans(&) conditioning, I call a seprate function (check), which 	will count the number of invalid nodes only


*/

int check(Node *root)
{
    if(root->left == NULL && root->right == NULL)
    return 0;
    
    int temp=0,real=0;
    
    if(root->left != NULL)
    {
        temp += (root->left->data);
        real += check(root->left);
    }
    
    if(root->right != NULL)
    {
        temp += (root->right->data);
        real += check(root->right);
    }
    
    if(root->data != temp)
    real += 1;
    
    return real;
    
}

// Return 1 if all the nodes in the tree satisfy the given property. Else return 0
int isSumProperty(Node *root)
{
 // Add your code here
    int val = check(root);
    // cout<<val<<"\n";
    
    if(val != 0)
    return 0;
    else
    return 1;
}
