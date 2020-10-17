/*

Ques:- Given an array A[] and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
      1) All elements smaller than a come first.
      2) All elements in range a to b come next.
      3) All elements greater than b appear in the end.
      The individual elements of three sets can appear in any order. You are required to return the modified arranged array.
      
Concept:- 1)Here we uses 3 variables,low points the index of value < a,mid points index for range [a,b] and high for elements > b

Time - O(n)
Space - O(1)
*/

vector<int> threeWayPartition(vector<int> A, int a, int b)
{
     //Your code here
     int low = 0,mid = 0,high = A.size()-1;
     
     while(mid <= high)
     {
         if(A[mid] < a)
         {
             swap(A[mid],A[low]);
             ++mid;
             ++low;
         }
         else if(A[mid] > b) //here only high is been reduced,to place and check A[mid] position again
         {
             swap(A[mid],A[high]);
             --high;
         }
         else
         ++mid;
     }
     
     return A;
}
