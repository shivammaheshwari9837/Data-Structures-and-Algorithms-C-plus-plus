/*

Ques :-Contruct a binary tree from Inorder ans Preorder traversal of array(Time-O(n*n), Space-(O(n) )

Concept:- 1.) For every subtree, we are extracting the required preorder and inorder array


*/

Node* helper(int preorder[],int inorder[],int preS,int preE,int inS,int inE)
    {
        //Base...
        if(inS > inE)
            return NULL;
        
        int rootData = preorder[preS];
        
        int rootIndex = -1;
        
        for(int i=inS;i <= inE; ++ i) // Finding the index of current subtree's root
        {
            if(rootData == inorder[i])
            {
                rootIndex = i;
                break;
            }
        }
        
        //Variables for left subtree.........
        int lPreS = preS + 1; //start of Preorder array
        int lInS = inS; // start of Inorder array
        int lInE = rootIndex - 1; // end of Inorder array
        int lPreE = lInE - lInS + lPreS; // end of Preorder array
        
        //Variables for right subtree...........
        int rPreS = lPreE + 1; //start of Preorder array
        int rPreE = preE; // end of Preorder array
        int rInS = rootIndex + 1; // start of Inorder array
        int rInE = inE; // end of Inorder array
        
        Node *root = new Node(rootData); // creating node...
        
        root->left = helper(preorder,inorder,lPreS,lPreE,lInS,lInE);
        
        root->right = helper(preorder,inorder,rPreS,rPreE,rInS,rInE);
        
        return root;
    }


Node* buildTree(int inorder[],int preorder[], int n)
{
//add code here.
     return helper(preorder,inorder,0,n-1,0,n-1 );
}
