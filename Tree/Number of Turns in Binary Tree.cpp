/*

Ques:- Given a binary tree and data value of two of its nodes. Find the number of turns needed to reach from one node to another in the given binary tree.

Concept:- 1)First we try to find LCA of given nodes
          2)Than from LCA, we find the location of both nodes, and try to find out how many turns are required to reach the both nodes from LCA
          3)Here , we will describes two terms ie. turns and the bend. The bend is a place where LCA is there(but it will calculated as turn in the question too)
          4)Special Case :- if any of the element is equal to LCA, than there will be no bend
                            if any element is not equal to LCA, than we will make answer + 1 ,as bend is there and thus calculated as turn
                            
Time - O(n)
Space - O(height)

*/

Node* lca(Node* root,int &first,int &second) //simple function to find the LCA of two nodes in a binary tree
{
    if(root == NULL)
    return NULL;
    
    if(root->data == first || root->data == second)
    return root;
    
    Node *l1 = lca(root->left,first,second);
    Node *l2 = lca(root->right,first,second);
    
    if(l1 == NULL && l2 == NULL)
    return NULL;
    else if(l1 != NULL && l2 != NULL)
    return root;
    else if(l1 != NULL)
    return l1;
    else
    return l2;
}

void calcu(Node *root,int &ele,int &ans,int turns,int val) // { current root, target element , answer , type of turn (-1 :- left , 1 :- right) , current number of turns }
{
    if(root == NULL)
    return;
    
    if(root->data == ele) //if tree data matches, add the number of turns 
    ans += val;
    
    if(turns == -1) //if currently at left path
    {
        calcu(root->left,ele,ans,-1,val); //turns remains same for left path
        calcu(root->right,ele,ans,1,val+1); // turns increased by 1 for right path
    }
    else //if currently at right path
    {
        calcu(root->left,ele,ans,-1,val+1); //turns increased by 1 for left path 
        calcu(root->right,ele,ans,1,val); //turns remains same for right path
    }
    
}

int NumberOFTurns(struct Node* root, int first, int second)
{
  // Your code goes here
  Node* ances = lca(root,first,second); //finding the LCA
  
  int ans = 0; //our answer
  
  //left subtree of LCA node..
  calcu(ances->left,first,ans,-1,0);  
  calcu(ances->left,second,ans,-1,0);
  
  //right subtree of LCA node...
  calcu(ances->right,first,ans,1,0);
  calcu(ances->right,second,ans,1,0);
  
  
  
  if(ances->data != first && ances->data != second) //if LCA is similar to one of the element
  ++ans;
  
  if(ans == 0)
  return -1;
  else
  return ans;
}
