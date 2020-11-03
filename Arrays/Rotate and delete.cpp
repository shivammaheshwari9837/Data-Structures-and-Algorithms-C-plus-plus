/*

Ques:- Given an array arr[] of N integers. Do the following operation n-1 times. For every Kth operation:

       1) Right rotate the array clockwise by 1.
       2) Delete the (n-k+1)th last element.
        Now, find the element which is left at last.
        
 Concept:- 1)Just observe the patteren form n = 1 to n = 20
           SIZE INDEX(answer)
            size=1, position=0
            ------------------------------------------------------------------------------
            size=2, position=1
            size=3, position=2
            size=4, position=1
            size=5, position=2
            ------------------------------------------------------------------------------
            size=6, position=2
            size=7, position=3
            size=8, position=2
            size=9, position=3
            ------------------------------------------------------------------------------
            size=10, position=3
            size=11, position=4
            size=12, position=3
            size=13, position=4
            
            ------------------------------------------------------------------------------
            size=14, position=4
            size=15, position=5
            size=16, position=4
            size=17, position=5
            ------------------------------------------------------------------------------
            size=18, position=5
            size=19, position=6
            size=20, position=5
            size=21, position=6

          So,  for odd N : floor( (n-3)/4 )+2
          for even N : floor( (n-2)/4 )+1
          
Time - O(1)
Space - O(1)

*/

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    if(n == 1)
    {
        cout<<arr1[0];
        return;
    }
    
    
    int index;
    
    if(n%2 == 0)
    index = (n-2)/4 + 1;
    else
    index = (n-3)/4 + 2;
    
    cout<<arr1[index];
}
