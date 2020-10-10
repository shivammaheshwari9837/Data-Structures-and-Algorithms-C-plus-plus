/*

Ques:- Given a complete binary tree, reverse the nodes present at alternate levels.

Concept:- 1)Just pass two pointer simultaneously with choices:- a)pass(root1->left,root2->right)
                                                                b)pass(root1->right,root2->left)
                                                                
Time - O(n)
Space - O(height)

*/

void helper(Node *root1,Node *root2,int lvl)
{
    //base..
    if(root1 == NULL)
    return;
    
    if(lvl % 2 == 0) //for alternative level
    swap(root1->data,root2->data);
    
    helper(root1->left,root2->right,lvl+1);
    helper(root1->right,root2->left,lvl+1);
}

void reverseAlternate(Node *root)
{
    //Your code here
    int lvl = 0;
    helper(root->left,root->right,lvl);
}
