/*

Ques:- Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Concept:-1.)We will do preorder traversal(left,right,root) first ie. approach is from leaves towards root
         2.)for every node, we will kept information{isValid(left/right) subtree,max size of (left/right)subtree, minimum value, maximum value), to check the validity of 
         the current node
         
Time - O(n) ,space - O(height


*/


/*

vector[0] = checks the validity ie.1(if valid) or 0(if valid)
vector[1] = original answer / max size of valid subtree
vector[2] = minimum value in the subtree(left/right depend on the call)
vector[3] = maximum value in the subtree(left/right depend on the call)

*/

vector<int>  helper(Node* root)
{
    if(root == NULL)   // if null, just return {valid, size = 0, just return anything, just return anything}
    return {1,0,INT_MIN,INT_MAX};
    
    auto a = helper(root->left); //left subtree info in vector a
    
    auto b = helper(root->right); // right subtree info in vector b
    
    if(a[0] == 1 && b[0] == 1 ) // if left and right subtree is valid
    {
        if(root->left  == NULL && root->right == NULL)  // if root is a leaf node
        return {1,a[1] + b[1] + 1,root->data,root->data}; //{valid,adding current root node also, min = root value,max = root value}
        
        if(root->left == NULL && root->data < b[2]) // if left subtree is NULL
        return {1,a[1] + b[1] + 1,root->data,b[3]}; //{valid,adding current root node also, min = root value,max remians same ie max of right subtree}
        
        if(root->right == NULL && root->data > a[3]) // if right subtree is NULL
        return {1,a[1] + b[1] + 1,a[2],root->data};   //{valid,adding current root node also, minimum of right subtree,max will be root value}
        
        
        if( root->data > a[3] && root->data < b[2]) // if both left and right subtree exits
        return {1,a[1] + b[1] + 1,a[2],b[3]};  // think by yourself
        else
        return {0,max(a[1],b[1]),0,0}; // no matter what should we return
    }
    else
    {
        return {0,max(a[1],b[1]),0,0};
    }
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
	//Your code here
	
	auto ans = helper(root);
	
	return ans[1];
}
