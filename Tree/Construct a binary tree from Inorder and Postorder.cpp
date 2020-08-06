/*

Ques :- Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

Concept:- 1.)take pen and paper , and just draw below
           Inorder:-     | Left | Root | Right | 
           Postorder :-      |Left | Right | Root|                     , as simple
           2.) We have to just find all six above components boundaries points , rest work will be done by 
               recursion.

*/

Node* helper(int in[],int post[],int inS,int inE,int postS,int postE)
{
    //base..
    if(inS > inE)
    return NULL;
    
    int rootData = post[postE]; // Since root will be last at postorder array
    int rootIndex = -1;
    
    for(int i=inS;i<=inE;++i) // finding the current root index in inorder array
    {
        if(rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }
    
    //variables for left subtree....
    int lPostS = postS; // start of postorder array
    int lInS = inS; // start of inorder array
    int lInE = rootIndex - 1; // end of inorder array
    int lPostE = lInE - lInS + lPostS; // end of postorder array
    
    //variables for right subtree.....
    int rPostS = lPostE + 1; // start of postorder array
    int rPostE = postE - 1; // end of postorder array
    int rInS = rootIndex + 1; // start of inorder array
    int rInE = inE; // end of inorder array
    
    Node *root = new Node(rootData); // creating root
    
    root->left = helper(in,post,lInS,lInE,lPostS,lPostE);//calling for left subtree
    
    root->right = helper(in,post,rInS,rInE,rPostS,rPostE); // calling for right subtree
    
    return root;
    
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return helper(in,post,0,n-1,0,n-1);
    /*Parameter are:-(  array(inorder),array(postorder),startIndex(inorder),endIndex(inorder),
    startIndex(postorder),endInder(postorder)  ) */
    
}
