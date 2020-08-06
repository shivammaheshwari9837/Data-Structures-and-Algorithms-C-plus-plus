/*

Ques :- Print Left View of a tree

Meaning:- The left view contains all nodes that are first nodes in their levels. Left View of 	a tree is defined as the nodes that would be visible to us from the left side.

Method 1:- USing preorder traversal

Intitution:- 1.) Find the height(or level)  of a tree
             2.) Declare an array of size of height and initialize with -1
             3.)Than simple do preorder travesal(first left side, than right side) and check that is it initialize via some node or still -1;

*/

int totalLevel(Node *root)
{
    if(root == NULL)
    return 0;
    
    int l1 = totalLevel(root->left);
    
    int l2 = totalLevel(root->right);
    
    return max(l1,l2) + 1;
}

void view(Node *root,vector<int> &ans,int lvl)
{
    if(root == NULL)
    return;
    
    if(ans[lvl] == -1)
    ans[lvl] = root->data;
    
    view(root->left,ans,lvl+1);
    
    view(root->right,ans,lvl+1);
    
    return;
}

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   // Your code here
   int totalLvl = totalLevel(root);
   
   vector<int> ans(totalLvl,-1);
   
   view(root,ans,0);
   
   for(int i=0;i<totalLvl;++i)
   cout<<ans[i]<<" ";
}

*/

Method 2:- USing queue

Steps:- 1.)Just print the first element of each level in a tree using queue

*/

void leftView(Node *root)
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
           
           if(i == 0)
           cout<<temp->data<<" ";
           
           if(temp->left != NULL)
           q1.push(temp->left);
           
           if(temp->right != NULL)
           q1.push(temp->right);
           
           
       }
       
   }
   
   return;
}
