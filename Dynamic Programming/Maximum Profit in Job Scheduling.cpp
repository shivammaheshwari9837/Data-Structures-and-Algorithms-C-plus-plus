// Ques Link :-       https://leetcode.com/problems/maximum-profit-in-job-scheduling/  

// Logic :- 

// 1) First sort jobs according to finish time.
// 2) Now apply following recursive process. 
//    // Here arr[] is array of n jobs
//    findMaximumProfit(arr[], n)
//    {
//      a) if (n == 1) return arr[0];
//      b) Return the maximum of following two profits.
//          (i) Maximum profit by excluding current job, i.e., 
//              findMaximumProfit(arr, n-1)
//          (ii) Maximum profit by including the current job            
//    }

// How to find the profit including current job?
// The idea is to find the latest job before the current job (in 
// sorted array) that doesn't conflict with current job 'arr[n-1]'. 
// Once we find such a job, we recur for all jobs till that job and
// add profit of current job to result.


// Code:-  


class Solution {
public:
    
    static bool comp(pair<int,pair<int,int>> &p1,pair<int,pair<int,int>> &p2){   //sort according to the end time.....
        return(p1.second.second<p2.second.second);
    }
    
    int nonConflict(int index,vector<pair<int,pair<int,int>>> &vp1){ //finding the non-conflicting index
        
        for(int i=index-1;i>=0;--i){
            if(vp1[index].second.first >= vp1[i].second.second)  //just find first index whose end time <= start time of current job
                return i;
        }
        
        return -1;
    }
    
    int maxPro(int index,vector<pair<int,pair<int,int>>> &vp1,int &size,vector<int> &dp){
        //base..
        if(index < 0){
            return 0;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        
        int a = vp1[index].first,b = 0;
        
        //take it...
        int nonConflictIndex = nonConflict(index,vp1);
        if(nonConflictIndex != -1)
            a +=  maxPro(nonConflictIndex,vp1,size,dp);
        
        
        
        //not take it.
        b = maxPro(index-1,vp1,size,dp);
        
        return dp[index] = max(a,b);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>> vp1;
        
        int size = startTime.size();
        vector<int> dp(size+1,-1);

        for(int i=0;i<size;++i){
            vp1.push_back({profit[i],{startTime[i],endTime[i]}});
        }
        
        sort(vp1.begin(),vp1.end(),comp);
        
        int ans = maxPro(size-1,vp1,size,dp);
        
        return ans;
    }
};
