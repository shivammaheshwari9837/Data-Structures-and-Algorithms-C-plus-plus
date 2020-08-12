/*

Ques:- Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

Concept:- 1.)It is similar to finding the length of cycles in a graph

*/


int minSwaps(int arr[], int n){
    /*Your code here */
    
    pair<int, int> arrPos[n]; 
	for (int i = 0; i < n; ++i) 
  { 
		arrPos[i].first = arr[i];  
		arrPos[i].second = i; 
	} 
	
	sort(arrPos, arrPos + n); // sort by first so the element is been arranged in order of their original possition
	
	vector<bool> vis(n, false); 

	int ans = 0; 
	for (int i = 0; i < n; ++i) 
	{ 
		if (vis[i] || arrPos[i].second == i) //if already visited or some ith element is already in its correct place
			continue; 
 
		int cycle_size = 0; 
		int j = i; 
		while (!vis[j])  //until cycle ends........
		{ 
			vis[j] = 1; 
			j = arrPos[j].second; 
			cycle_size++; 
		} 
      
			ans += (cycle_size - 1); 
	} 
	return ans; 
    
}
