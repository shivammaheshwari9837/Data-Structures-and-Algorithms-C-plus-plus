/*

Ques Given an unsorted array of size n. Array elements are in the range from 1 to n. 
One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
Find these two numbers, Time-O(n), Space-O(1).

Theory:- Traverse the array. While traversing, use the absolute value of every element as 
an index and make the value at this index as negative to mark it visited. If something is
 already marked negative then this is the repeating element. To find missing, traverse the 
array again and look for a positive value.

*/


void work()
{
    int n;
    cin>>n;
    
    int arr1[n+1];
    
    for(int i=1;i<=n;++i)
    {
        cin>>arr1[i];
    }
    
    //Time-O(n),Space-O(1)
    
    
    //Repeating elemnt..
    for(int i=1;i<=n;++i)
    {
        if(arr1[abs(arr1[i])]>0)
        arr1[abs(arr1[i])]=-arr1[abs(arr1[i])];
        else
        cout<<abs(arr1[i])<<" ";
    }
    
    for(int i=1;i<=n;++i)
    {
        if(arr1[i]>0)
        cout<<i;
    }
    
    
}
