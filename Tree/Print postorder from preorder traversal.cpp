/*

Ques :- Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.
(Time - O(n) , space -O(n) ie. stack size)

Concept:-  1.) For every node , setting up a certian range to check validity (ie. some lower and upper)
            2.) if move towards left subtree(lower remains same, upper changes to current value)
             3.) if move towatds right subtree(upper remains same, lower changes to current value
              4.) This will be done recursively , as postorder, node will be printed at last(as----->left,right,root)

*/

void postorderGen(int arr1[],int &index,int low,int upp,int n)
{
    //base...
    if(index == n || arr1[index]<low || arr1[index]>upp)
    return;
    
    int val = arr1[(index)++];
    
    postorderGen(arr1,index,low,val,n); //for left subtree, only lower range becomes current node value
    postorderGen(arr1,index,val,upp,n); //for right subtree, only upper range becomes current node value
    
    cout<<val<<" ";  // since postorder, than printed after left and right subtree is visited
}

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    int index = 0,low = INT_MIN,upp = INT_MAX;
    
    postorderGen(arr1,index,low,upp,n);
}
