/*

Ques :- Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.

Method 1:- Time- O(n) , space - O(height) 

Concept:- 1.)similar to :- taking inorder traversal in an array ,than two cases :- a) if two pairs found that are incorrect
                                                                           b) if one incorrect pair found(wrong nodes are adajacent )
	2.) now think in the form of BST, where information of just previous node required in inorder traversal only.
  
 */
 
 void helper(Node *root,Node* &prev,Node* &n1,Node* &n2) //value of prev is passed by reference due to storing the previous node
{
    if(root == NULL)
    return;
    
    helper(root->left,prev,n1,n2); //towards left subtree
    
    if(prev && (prev->data > root->data))  // if prev.data > root.data
    { 
        if(n1 == NULL) //first pair found
        {
            n1 = prev;
        }
        n2 = root;   // changes even when second pair found
    }
    
    prev = root;  //before going towards right subtree, prev must be = root
    
    helper(root->right,prev,n1,n2);
    
    return;
}


struct Node *correctBST( struct Node* root )
{
    // add code here.
    Node *curr = root,*prev = NULL,*n1 = NULL,*n2 = NULL;
    
    helper(curr,prev,n1,n2);  //(current node,previous node in inorder traverasl ,n1,n2)
    
    swap(n1->data,n2->data);
    
    return root;
}
