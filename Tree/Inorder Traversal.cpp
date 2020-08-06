/*

Ques :- Inorder Traversal (left,root,right)

*/

void traversal(Node *root,vector<int> &ans)
{
    if(root == NULL)
    return;
    
    traversal(root->left,ans);
    
    ans.push_back(root->data);
    
    traversal(root->right,ans);
    
    // return;
    
}

vector<int> inOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  traversal(root,ans);
  return ans;
}
