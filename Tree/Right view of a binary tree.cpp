/*

Ques :- Right view of a binary tree

Concept:- 1.)Similar to (left view of binary tree)  question
	  2.) just print the last node of each level

*/

void rightView(Node *root)
{
    if(root == NULL)
    return;
    
   // Your code here
   queue<Node*> q1;
   q1.push(root);
   
   while(!q1.empty())
   {
       int len = q1.size();
       
       for(int i=0;i<len;++i)
       {
           Node *temp = q1.front();
           q1.pop();
           
           if(i == len-1)
           cout<<temp->data<<" ";
           
           if(temp->left != NULL)
           q1.push(temp->left);
           
           if(temp->right != NULL)
           q1.push(temp->right);
           
           
       }
       
   }
   
   return;
}
