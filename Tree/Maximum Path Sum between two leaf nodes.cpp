/*

Ques :- Maximum Path Sum between two leaf nodes(Time - O(n) ) 

Institution:- 1.)similar to diameter of a tree
		2.) Gathering information on every node(except lef node and node having one child, since can't be a path from leaf to leaf ) 


*/

#define ll long long

ll ans;

ll maxSum(Node *root)
{
    if(root == NULL)
    return INT_MIN;
    
    ll l1 = maxSum(root->left);
    
    ll l2 = maxSum(root->right);
    
    if(!(root->left == NULL || root->right == NULL)) /*if left subtree or right subtree is 	NULL,means leaf node or node with one child not considered as a path*/
    ans = max(ans,l1 + l2 + (root->data)); // Final answer
    
    if(l1 == INT_MIN && l2 == INT_MIN) //if it is a leaf, just return root->data
    return (root->data);
    else
    return (max(l1,l2) + (root->data)); //maximum of left or right subtree
}

int maxPathSum(Node* root)
{
    ans = INT_MIN;
    // code here  
    ll v = maxSum(root);
    
    return ans;
}
