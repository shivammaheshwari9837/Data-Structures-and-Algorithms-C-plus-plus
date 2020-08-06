/*

Ques:- Given two BST, Return elements of both BSTs in sorted form.

Concept:-1.)First convert both BST into Doubly Linked List( try first convert tree to DLL at GFG)
         2.) Than simply merge them using merge(either iterative or recusive) two sorted array concept

*/

void add(Node* root,Node* &dou,Node* &douT)
{
    if(dou == NULL)
    {
        dou = root;
        douT = root;
        douT->left = NULL;
        douT->right = NULL;
    }
    else
    {
        douT->right = root;
        root->left = douT;
        root->right = NULL;
        
        douT = douT->right;
    }
}

void helper(Node *root,Node* &dou,Node* &douT)
{
    //base
    if(root == NULL)
    return;
    
    Node* le = root->left;
    Node *ri = root->right;
    
    helper(le,dou,douT);
    
    add(root,dou,douT);
    
    helper(ri,dou,douT);
    
    return;
}

void merging(Node *root1,Node *root2,vector<int> &ans)
{
    //base..
    if(root1 == NULL)
    {
        while(root2!=NULL)
        {
            ans.push_back(root2->data);
            root2 = root2->right;
        }
        return;
    }
    
    if(root2 == NULL)
    {
        while(root1!=NULL)
        {
            ans.push_back(root1->data);
            root1 = root1->right;
        }
        return;
    }
    
    if(root1->data < root2->data)
    {
        ans.push_back(root1->data);
        merging(root1->right,root2,ans);
        return;
    }
    else
    {
        ans.push_back(root2->data);
        merging(root1,root2->right,ans);
        return;
    }
    
}

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   Node *dou1 = NULL,*douT1 = NULL,*dou2 = NULL,*douT2 = NULL;
   
   helper(root1,dou1,douT1);  // convert BST 1 to DLL
   helper(root2,dou2,douT2); //covert BST 2 to DLL
   
   vector<int> ans;
   
   merging(dou1,dou2,ans);  // simply merging
   
   return ans;
   
}
