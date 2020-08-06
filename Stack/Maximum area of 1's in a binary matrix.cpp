/*

Ques :- Maximum area of 1's in a binary matrix(TLE m phasa thaaa......)

Concept:- 1.Related to Maximum area in histogram
	2. Convert each row as ground level , then pass it as a histogram....

*/

int max_in_histo(int arr1[] , int n)
{
    
    vector<int> ans1,ans2;
    
    stack<pair<int,int> > s1,s2;
    
    
    //Next Smaller to left............
    s1.push({arr1[0] , 0});
    ans1.push_back(1);
    
    for(int i=1;i<n;++i)
    {
        while(s1.size()!=0 && s1.top().first>=arr1[i])
        {
        	s1.pop();
		}
        
        if(s1.size()!=0 && s1.top().first<arr1[i])
        {
            ans1.push_back(i - s1.top().second);
            s1.push({ arr1[i] ,i });
        }
        else if(s1.size() == 0)
        {
            ans1.push_back(i+1);
            s1.push({ arr1[i] ,i} );
        }
    }
    
    
    //Next smaller to right................
    s2.push({arr1[n-1] , n-1});
    ans2.push_back(1);
    
    for(int i=n-2;i>=0;--i)
    {
    	while(s2.size()!=0 && s2.top().first>=arr1[i])
    	s2.pop();
    	
    	if(s2.size()!=0 && s2.top().first<arr1[i])
    	{
    		ans2.push_back(s2.top().second - i);
    		s2.push({arr1[i] , i});
		}
		else if(s2.size() == 0)
		{
			ans2.push_back(n-i);
			s2.push({arr1[i] , i});
		}
	}
	
	reverse(ans2.begin(),ans2.end());
	
	
	//Final calculation....
	int res = 0;
	
	for(int i=0;i<n;++i)
	{
		int temp = ans1[i] + ans2[i] -1;
//		cout<<ans1[i]<<" "<<ans2[i]<<"\n";
		res = max(res , arr1[i]*temp);
	}
// 	cout<<res;
    
    return res;
    
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int arr1[m],temp1[m];
    int res=0,t1;
    
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            for(int j=0;j<m;++j)
            {
                arr1[j]=M[i][j];
                temp1[j]=M[i][j];
            }
            t1 = max_in_histo(arr1,m);
            res = max(res,t1);
        }
        else
        {
            for(int j=0;j<m;++j)
            {
                if(M[i][j] == 0)
                arr1[j]=0;
                else
                arr1[j] = temp1[j] + M[i][j];
            }
            t1 = max_in_histo(arr1,m);
            res = max(res,t1);
            
            for(int j=0;j<m;++j)
            temp1[j] = arr1[j];
        }
    }
    return res;
    
}
