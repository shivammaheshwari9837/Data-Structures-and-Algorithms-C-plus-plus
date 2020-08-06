/*

Ques :- Serialize and Deserialize a Binary Tree in O(n) 

Concept:- 1.)Simple do a preorder traversal first while storing in the array A
          2.) Observe the preorder recursion(that how it reaches to left most deep and think how to recover it using some global variable or so
          
*/

void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(root == NULL)
    {
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    
    serialize(root->left,A);
    serialize(root->right,A);
    
    return;
}

/*this function deserializes
 the serialized vector A*/
 
int ind; 
Node* helper(vector<int> &A)
{
    ++ind;
    //Base...
    if( A[ind] == -1)
    return NULL;
    
    Node *root = new Node(A[ind]);
    
    root->left = helper(A);
    
    root->right = helper(A);
    
    return root;
}
 
Node * deSerialize(vector<int> &A)
{
   //Your code here
   if(A[0] == -1)
   return NULL;
   
   ind=-1;
   return helper(A);
}

