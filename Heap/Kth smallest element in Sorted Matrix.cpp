/*

Ques:- Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Concept:- 1)This problem can be easily converted to 'Kth Smallest Number in M Sorted Lists'. As each row (or column) of the given matrix can be seen as a sorted list, 
            we essentially need to find the Kth smallest number in ‘N’ sorted lists.
          2)So , here we will use minHeap of size k, where we first try to discard the k-1 smallest values from the heap,leads to answer
          
Time - O(min(N,K) + Klog min(K,M) )
Space - O(n)

*/

#define pii pair<int,pair<int,int> >

struct comp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.first>b.first;
    }
};


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<pii,vector<pii>,comp> minHeap;  //(element of matrix,row_num,col_num) is the structure
  
  //first try to push first elements of first rows....
  for(int i=0;i<n;++i)
  {
      minHeap.push({mat[i][0],{i,0}});
  }
  
  int res,coun = 0;
  
  while(!minHeap.empty())
  {
      pii heapTop = minHeap.top();
      res = heapTop.first; //store the answe into the res
      minHeap.pop();
      
      ++coun;
      if(coun == k) //if count == k,break the loop
      break;
      
      ++heapTop.second.second;
      if(heapTop.second.second < n) //if exceeds the column limit of some ith row,do nothing
      {
          heapTop.first = mat[heapTop.second.first][heapTop.second.second];
          minHeap.push(heapTop);
      }
  }
  
  return res;
  
}
