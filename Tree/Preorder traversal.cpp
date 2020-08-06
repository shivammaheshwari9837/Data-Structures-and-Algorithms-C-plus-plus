/*

Ques :- Preorder traversal(root,left,right)

*/

void travel(Node *root,vector<int> &ans)
{
    if(root == NULL)
    return;
    
    ans.push_back(root->data);
    
    travel(root->left,ans);
    
    travel(root->right,ans);
    
    return;
}

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  travel(root,ans);
  return ans;
  
}
