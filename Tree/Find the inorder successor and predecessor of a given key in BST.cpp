/*

Ques 48:- There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, 
if the either of predecessor or successor is not found print -1.

Concept:- 
  for predecessor:- 1.) if current root value is less than key(that may be answer), we than traverse towards right subtree
                    2.) if current root  value is greater or equal than the key , we than traverse towards left subtree

*/

void findPre(Node *root,Node *&pre,int key)
{
    if(root == NULL)
    return;
    
    if(root->key < key) //  if current root value is less than key(that may be answer), we than traverse towards right subtree
    {
        pre = root;
        
        findPre(root->right,pre,key);
    }
    else
    findPre(root->left,pre,key); // if current root  value is greater or equal than the key , we than traverse towards left subtree
    
}

void findSuc(Node *root,Node *&suc,int key)
{
    if(root == NULL)
    return;
    
    if((root->key) > key) 
    {
        suc = root;
        findSuc(root->left,suc,key);
    }
    else
    {
        findSuc(root->right,suc,key);
    }
    
    return;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    pre = NULL;
    suc = NULL;
    
    findPre(root,pre,key);
    
    findSuc(root,suc,key);
    
    return;
    
}
