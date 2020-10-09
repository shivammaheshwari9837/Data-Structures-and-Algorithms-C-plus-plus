/*

Ques:- Given a special Binary Tree whose leaf nodes are connected to form a circular doubly linked list. Find the height of this special Binary Tree.

Concept:- 1)here we have to identify speacial property of a DLL,ie...
                                                            a)The right child of the left child of the current node is the node itself.
                                                            b)The left child of the right child of the current node is the node itself.
          2)So,to identify the leaves,we will check the one of the following conditions
          
Time - O(height)
Space - O(height)

*/

int height(Node *root) //simple finding height of a binary tree code
{
    //base..
    if(root == NULL)
    return 0;
    
    if(root->right!= NULL && root->right->left != NULL && root->right->left == root) //simple checking the conditions of DLL
    return 1;
    
    int a = height(root->left) + 1;
    int b = height(root->right) + 1;
    
    return max(a,b);
}

int findTreeHeight(Node* root)
{
	// Code here
	
	if(root->left == NULL && root->right == NULL)
	return 1;
	
	int ans = height(root);
	
	return ans;
}
