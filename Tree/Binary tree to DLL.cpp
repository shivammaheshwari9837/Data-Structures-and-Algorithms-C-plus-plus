/*

Ques :- Binary tree to DLL(in O(n) time)

*/

Node *dou,*douT; // doub = head of DLL, doubT = tail of DLL(which will incremented)

void add(Node* root)
{
    if(dou == NULL) // if first node is added
    {
        dou = root;
        douT = root;
        douT->left = NULL;
        douT->right = NULL;
    } 
    else // if node is not first node.........
    {
        douT->right = root;
        root->left = douT;
        root->right = NULL;
        
        douT = douT->right;
    }
}

void helper(Node *root)
{
    //base
    if(root == NULL)
    return;
    
    if(root->left == NULL and root->right == NULL) // for leaf node
    {
        add(root); // just adding the current node
        return;
    }
    
    Node* le = root->left; // have to take in variable as we will loose them when try to connect 
    Node *ri = root->right; // implicitly (dont think it as extra space as similar to just stack space)
    
    //since inorder traversal(left,root,right)...................
    
    helper(le); // for left
    
    add(root); // just adding the current node (for root)
    
    helper(ri); // for right 
    
    return;
}

Node * bToDLL(Node *root)
{
    // your code here
    
    if(root == NULL)
    return NULL;
    
    dou = NULL,douT = NULL;
    
    helper(root); // helper function
    
    return dou;
}
