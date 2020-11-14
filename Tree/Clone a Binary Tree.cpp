/*

Ques:- Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.

Concept:- 1)Here we will use the concept of Hashing
          2)We will create key of table as original node, and value as the new duplicate node
          3)Than pick up the value of random node for clone tree form tha hash table
          
Time - O(n)
Space - O(n)

*/

Node* helper(Node* root,unordered_map<Node*,Node*> &ump1) //just simple traversal
{
    //base...
    if(root == NULL)
    return NULL;
    
    Node *temp = new Node(root->data); //creating a new node
    ump1[root] = temp; //making hash table
    
    temp->left = helper(root->left,ump1);
    temp->right = helper(root->right,ump1);
    
    return temp;
}

void copyRandom(Node *root,Node *cRoot,unordered_map<Node*,Node*> &ump1)
{
    if(root == NULL)
    return;
    
    cRoot->random = ump1[root->random]; //implementing the random pointer for clone tree
    
    copyRandom(root->left,cRoot->left,ump1);
    copyRandom(root->right,cRoot->right,ump1);
}
   
Node* cloneTree(Node* tree)
{
   //Your code here
   unordered_map<Node*,Node*> ump1; //{key as node from original tree : value as node of cloned tree}
   
   Node *cloneRoot = helper(tree,ump1);
   
   copyRandom(tree,cloneRoot,ump1);
   
   return cloneRoot;
}
