/*

Ques :- Given a tree, convert it into its mirror(Time-(n),Space-O(height) )

Concept:- 1.) Just switch the left and right child of a node recusively.


*/

void mirror(Node* node) 
{
     // Your Code Here
     if(node == NULL)
     return;
     
     mirror(node->left);
     
     mirror(node->right);
     
     Node *temp = node->left;
     
     node->left = node->right;
     
     node->right = temp;
     
     return;
}
