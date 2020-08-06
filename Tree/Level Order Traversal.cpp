/*

Ques :- Level Order Traversal (simple BFS)

*/

vector<int> levelOrder(Node* node)
{
  //Your code here
  vector<int> ans;
  
  queue<Node*> q1;
  q1.push(node);
  
  while(!q1.empty())
  {
      int ele = q1.front()->data;
      
      ans.push_back(ele);
      
      if(q1.front()->left != NULL)
      q1.push(q1.front()->left);
      
      if(q1.front()->right != NULL)
      q1.push(q1.front()->right);
      
      q1.pop();
      
  }
  
  return ans;
}
