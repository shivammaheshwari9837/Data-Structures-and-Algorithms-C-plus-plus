/*

Ques :-  Given an array arr of size n, write a program that prints 1 if given array can represent preorder traversal of a BST, else prints 0.
(Time - O(n) , space -O(n) ie. stack size)

Concept:-  1.) For every node , setting up a certian range to check validity (ie. some lower and upper)
            2.) if move towards left subtree(lower remains same, upper changes to current value)
             3.) if move towatds right subtree(upper remains same, lower changes to current value
              4.) This will be done recursively

*/

void helper(int arr1[],int &index,int low,int upp,int n)
{
    //base.......
    if(index == n || arr1[index] < low || arr1[index] > upp)
    {
        return;
    }
    
    int val = arr1[(index)++];
    
    helper(arr1,index,low,val,n);  // if move towards left subtree(lower remains same, upper changes to current node value)
    
    helper(arr1,index,val,upp,n); //if move towatds right subtree(upper remains same, lower changes to current node value
    
    return;
    
}

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    int index = 0,low = INT_MIN,upp = INT_MAX;
    helper(arr1,index,low,upp,n);
    
    cout<<(index == n);
}
