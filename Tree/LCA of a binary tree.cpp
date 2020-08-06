/*

Ques :- LCA of a binary tree

Concept:-1.)for a particular node, the return type of left subtree and right subtree are not 	NULL, than the current node(or root node) is LCA.
	2.)if node A is a decendent of node B(means lie in the same path), algorithms work 	automatically

*/

Node* findLCA(Node *root,int n1,int n2)
{
    if(root == NULL)
    return root;
    
    if(root->data == n1 || root->data == n2)
    return root;
    
    Node *p1 = findLCA(root->left,n1,n2);
    
    Node *p2 = findLCA(root->right,n1,n2);
    
    if(p1 == NULL && p2 == NULL)
    return NULL;
    else if(p1 != NULL && p2 != NULL)
    return root;
    else if(p1 != NULL)
    return p1;
    else
    return p2;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
   
   Node *ans = findLCA(root,n1,n2);
   
   return ans;
   
}
