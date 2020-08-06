/*

Ques :- Reverse Level Order Traversal 

Concept:- Using stack DS

*/

void reversePrint(Node *p)
{
    //Your code here
    queue<Node*> q1;
   q1.push(p);
   
   
   vector<int>helper;
   stack<int> s1;
   
   while(!q1.empty())
   {
       int siz = q1.size();
       helper.clear();
       
       for(int i=0;i<siz;++i)
       {
           Node *tempNode = q1.front();
           
           helper.push_back(tempNode->data);
           
           if(tempNode->left != NULL)
           q1.push(tempNode->left);
           
           if(tempNode->right != NULL)
           q1.push(tempNode->right);
           
           q1.pop();
       }
       
        for(int i=siz-1;i>=0;--i)
        s1.push(helper[i]);
       
   }
   
   while(!s1.empty())
   {
       cout<<s1.top()<<" ";
       s1.pop();
   }
}
