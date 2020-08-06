/*

Ques :- Count number of leaves in a binary tree

Method 1:- in O(n) space using queue

*/

int countLeaves(Node* root)
{
  // Your code here
  queue<Node*> q1;
  q1.push(root);
  
  int cLeaves=0;
  
  while(!q1.empty())
  {
      if(q1.front()->left == NULL && q1.front()->right == NULL)
      ++cLeaves;
      else 
      {
          if(q1.front()->left != NULL)
          q1.push(q1.front()->left);
          
          if(q1.front()->right != NULL)
          q1.push(q1.front()->right);
      }
      
      q1.pop();
  }
  
  return cLeaves;
}


/*

Method 2:- (using recursion)

*/

int countLeaves(Node* root)
{
  // Your code here
  if(root == NULL) return 0;
  else if(root->left == NULL && root->right == NULL)
  return 1;
  else
  return(countLeaves(root->left) + countLeaves(root->right));
}
