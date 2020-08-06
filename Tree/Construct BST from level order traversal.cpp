/*

Ques :- Given an array of size N containing level order traversal of a BST. The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) 
from its given level order traversal. (Time - O(n) and space - O(n) )

Concept:- 1.)the idea is similar to convert BST into its level order traversal using the queue DS
	2.) for every node, we keep the track of :- minRange,Node,maxRange to avoid wrong formation


*/

Node* constructBst(int arr[], int n)
{
    
    // Code here
    Node *root = new Node(arr[0]);
    
    queue<tuple<int,Node*,int> > q1; //structure(minValue,Node,maxValue)
    q1.push(make_tuple(INT_MIN,root,INT_MAX));  //initialization
    
    int i=1;
    
    while(i<n)
    {
        int minV = get<0>(q1.front());
        Node *temp = get<1>(q1.front());
        int maxV = get<2>(q1.front());
        
        if((arr[i]< temp->data) && (arr[i]>minV))  //check if current value at arr[i] can be a left child
        { 
            Node *vertex = new Node(arr[i++]);
            temp->left = vertex;
            q1.push(make_tuple(minV,vertex,temp->data));
        }
        
        if((i<n) && (arr[i]> temp->data) && (arr[i]<maxV)) //check if current value arr[i] can be a right child too
        {
            Node *vertex = new Node(arr[i++]);
            temp->right = vertex;
            q1.push(make_tuple(temp->data,vertex,maxV));
        }
        
        q1.pop();
    }
    
    return root;
	
}
