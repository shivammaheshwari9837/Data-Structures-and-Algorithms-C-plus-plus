/*

Ques :- Check number of elements in BST in some range [l,r] (in O(k) ,where k is the number of elemets)

Concept:-  1.) if current root (of a subtree) lies in between the range
          2.)if current root (of a subtree) is lesser(or equal ) than lower range,moves to right subtree
          3.) if current root (of a subtree) if greator (or equal) than upper range, moves to left subtree

*/


void helper(Node *root,int l,int r,int *coun)
{
    if(root == NULL)
    return;
    
    int val = root->data;
    
    if(val>l and val<r) // if current root (of a subtree) lies in between the range
    {
        *coun+=1;
        helper(root->left,l,r,coun);
        helper(root->right,l,r,coun);
    }
    else if(l >= val) // if current root (of a subtree) is lesser(or equal ) than lower range,moves to right subtree
    {
        if(val == l)
        *coun+=1;
        
        helper(root->right,l,r,coun);
    }
    else  // if current root (of a subtree) if greator (or equal) than upper range, moves to left subtree
    {
        if(r == val)
        *coun+=1;
        
        helper(root->left,l,r,coun);
    }
    
    return;
}

int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here 
    int coun = 0;
    
    helper(root,l,h,&coun);
    
    return coun;
}
