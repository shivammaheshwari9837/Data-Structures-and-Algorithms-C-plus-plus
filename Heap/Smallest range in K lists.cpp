/*

Ques:- Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are 
        found, find the first such range found.

Concept:- 1)To maintain all elements in range and much exists in every K list,we will use the minHeap.
          2)we will maintain a pointer in the at every element in the heap too
          3)at every updation, we try to check the minimal range exits
          
Time - O(n * k * log k)
Space - O(k)

*/

#define pii pair<int,pair<int,int> >

struct comp
{
  bool operator()(const pii &a,const pii &b)
  {
      return a.first > b.first;
  }
};

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      priority_queue<pii,vector<pii>,comp> minHeap; //(element,row number,column number)
      
      int maxi = 0;
      
      for(int i=0;i<k;++i) //first insert first element of every row
      {
          maxi = max(maxi,arr[i][0]);
          minHeap.push({arr[i][0],{i,0}});
      }
      
      int diff = INT_MAX,tempDiff;
      pair<int,int> ans;
      
      while(!minHeap.empty())
      {
          pii curr = minHeap.top();
          minHeap.pop();
          
          int ele = curr.first;
          tempDiff = maxi - ele;
          
          if(tempDiff < diff)
          {
              diff = tempDiff;
              ans.first = ele;
              ans.second = maxi;
          }
          
          ++curr.second.second;
          if(curr.second.second < n) //if the column number is in range only than proceeds
          {
              curr.first = arr[curr.second.first][curr.second.second];
              maxi = max(maxi,curr.first);
              minHeap.push(curr);
          }
          else //if not it range,than proceeding is completely useless,since alleast 1 one lie inside every K lists
          break;
      }
      
      return ans;
}
