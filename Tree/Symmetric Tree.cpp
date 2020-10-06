/*

Ques:- Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Concept:- 1)Simple is to pass two simlultaneous nodes in recurion, ie. in opposite direction

Time - O(n)
Space - O(height)

*/

bool helper(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    return true;
    
    if(root1 == NULL || root2 == NULL)
    return false;
    
    bool a = helper(root1->left,root2->right);
    
    bool b = true;
    if(root1->data != root2->data)
    b = false;
    
    bool c = helper(root1->right,root2->left);
    
    return (a & b & c);
}

bool isSymmetric(struct Node* root)
{
	// Code here
	if(root == NULL)
	return true;
	
	bool ans = helper(root,root);
	
	return ans;
}
