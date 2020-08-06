/*

Ques :- Check for BST (Time - O(n) ,space - O(height) )

Concept:- 1.)for every node , we are setting up the upper and lower limit, thus current node value should be lie inside this range(exclusivley).

*/

bool helper(Node *root,int low,int upp)
{
    //base...
    if(root == NULL)
    return true;
    
    
    bool c;
    
    if((root->data > low) && (root->data < upp)) //is lie in range
    c = true;
    else
    c = false;
    
    bool a = helper(root->left,low,root->data); //if left subtree, upper will be = root->data
    
    bool b = helper(root->right,root->data,upp); //if right subtree , lower = root->data
    
    return (a & b & c);
}

bool isBST(Node* root) {
    // Your code here
    return helper(root,INT_MIN,INT_MAX);
    
}
