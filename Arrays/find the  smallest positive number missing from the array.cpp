/*

Ques :- You are given an array arr[] of N integers including 0. The task is to find the 
smallest positive number missing from the array.(T=O(n) , S=O(1) )

Theory: -Similar to missing and repeating...


*/

int missingNumber(int arr[], int n) { 
    
    // Your code here
    int total_pos=0;
    
    for(int i=0;i<n;++i)
    {
        if(arr[i]>0)
        ++total_pos;
    }
    
    //shift...
    int m=0;
    for(int i=0;i<total_pos;++i)
    {
        m=i;
        if(arr[i]<=0)
        {
            while(arr[m]<=0 && m<n)
            {
                ++m;
            }
            swap(arr[i],arr[m]);
        }
    }
    
    for(int i=0;i<total_pos;++i)
    {
        if((abs(arr[i])-1)<total_pos && arr[abs(arr[i])-1]>0)
        arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    
    for(int i=0;i<total_pos;++i)
    {
        if(arr[i]>0)
        return i+1;
    }
    
    return total_pos+1;
    
    
}
