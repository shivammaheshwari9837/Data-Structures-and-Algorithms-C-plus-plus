/*

Ques 50:- Given a Binary Search Tree of size N, that may be unbalanced. Your task is to complete the function buildBalancedTree(), that convert the given BST into a 
balanced BST that has minimum possible height.(T - O(n) and space - O(n) )

Concept:- 1.)store the inorder traversal of BST in an vector
	2.) than find the mid of vecotor recursively thus adding corresponding to left and right child

*/

void inorder(Node *root,vector<int> &v1) //inorder traversal 
{
    if(root == NULL)
    return;
    
    inorder(root->left,v1);
    
    v1.push_back(root->data);
    
    inorder(root->right,v1);
    
    return;
}

void balancing(Node *&head,int low,int upp,vector<int> &v1) // head is been passed 
{
    //base condition..
    if(low>upp)
    return;
    
    int mid = (low + upp)/2; // finding the mid of v1 vector
    
    head = new Node(v1[mid]); //making head pointing to the new node
    
    balancing(head->left,low,mid-1,v1);
    
    balancing(head->right,mid+1,upp,v1);
    
    return;
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> v1;
	inorder(root,v1);
	
	Node *head = NULL;
	
	int low = 0,upp = v1.size()-1;
	
	balancing(head,low,upp,v1);//call
	
	return head;
}
