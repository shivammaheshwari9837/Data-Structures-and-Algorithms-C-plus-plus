/*

Ques :- Given a Binary Tree, your task is to print its level order traversal such that each level is separated by $.

Intitution:- 1.)It may be said as a variation of two questions ie. left view of a tree and right view of a tree

*/

void levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q1;
  q1.push(node);
  
  while(!q1.empty())
  {
      int temp_siz = q1.size();
      
      for(int i=0;i<temp_siz;++i)
      {
          Node *p = q1.front();
          
          cout<<p->data<<" ";
          
          if(p->left != NULL)
          q1.push(p->left);
          
          if(p->right != NULL)
          q1.push(p->right);
          
          q1.pop();
      }
      cout<<"$ "; 
  }
}
