/*

Ques :- Print leaf nodes from preorder traversal of BST (time- O(n), space - O(n) ) 

Concept:- 1.) For every node , setting up a certian range to check validity (ie. some lower and upper)
            2.) if move towards left subtree(lower remains same, upper changes to current value)
             3.) if move towatds right subtree(upper remains same, lower changes to current value
              4.) This will be done recursively
		5.)make return type boolean,an observe that in this method, when left and right subtree called, and if both calls return false
    (means nither valid left and right subtree exist), than this must be a leaf node
    
    
    */
    
    
    bool postorderGen(int arr1[],int &index,int low,int upp,int n)
{
    //base...
    if(index == n || arr1[index]<low || arr1[index]>upp)
    return false;
    
    int val = arr1[(index)++];
    
    bool a = postorderGen(arr1,index,low,val,n); //for left subtree, only lower range becomes current node value
    bool b = postorderGen(arr1,index,val,upp,n); //for right subtree, only upper range becomes current node value
    
    if(a == false && b == false) // if a and b are false, means no left and right subtree exists
    cout<<val<<" ";  // it will be leaf
    
    return true;
}

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    int index = 0,low = INT_MIN,upp = INT_MAX;
    
    bool v = postorderGen(arr1,index,low,upp,n);
}
    
    
