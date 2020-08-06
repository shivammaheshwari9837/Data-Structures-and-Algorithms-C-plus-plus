/*

Ques :- Leaves to DLL(inorder traversal) and remove all that leaves too form the original tree in (n) time and O(H) space(for recusrion calls)

Steps:- 1) First keep in mind the concept of DLL and their pointer's pointing direction, rest is easy and do 

*/

Node *doub,*doubT; // doub  = head of DLL , doubT  = tail required for iteration
void helper(Node *root,Node *par,bool choice)
{
    //Base...
    
    if(root == NULL) // for having a one child ,it will return here...
    {
        return;
    }
    
    if(root->left == NULL && root->right == NULL) // if really a leaf node...
    {
        if(doub == NULL) // if first time encounter a leaf node.../ head of DLL
        {
            doub = root;
            doubT = root;
            doubT->left = NULL;
            doubT->right = NULL;
        }
        else  //if first left node is settled down, rest is iteartion of DLL
        {
            doubT->right = root;
            root->left = doubT;
            root->right = NULL;
            
            doubT = doubT->right;
            
        }
        
        if(choice == 0) // it is a left child
        par->left = NULL;
        else //or a right child
        par->right = NULL;
        
        return;
        
    }
    
    //Simple inorder traversal...
    helper(root->left,root,0); // 0 is passed as left child
    
    helper(root->right,root,1); // 1 is passed as right child
}

Node * convertToDLL(Node *root){
    // add code here.
    
    if((root == NULL) || (root->left == NULL && root->right == NULL)) // Base condition...
    return root;
    
    doub = NULL,doubT = NULL;
    
    helper(root,NULL,-1); // (root node, parent node , choice variable(ie left or right child) )
    
    return doub;
}
