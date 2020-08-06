/*

Ques  :- Given an array A of size N having distinct elements, the task is to find the next 
greater element for each element of the array in order of their appearance in the array. 
If no such element exists, output -1 

*/

void work()
{
    ll n;
    cin>>n;
    
    ll arr1[n];
    vector<ll> ans;
    
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    stack<ll> s1;
    s1.push(arr1[n-1]);
    
    ans.push_back(-1);
    
    for(int i=n-2;i>=0;--i)
    {
        while(s1.size()!=0 && s1.top()<=arr1[i])
        s1.pop();
        
        if(s1.size()!=0 && s1.top()>arr1[i])
        {
            ans.push_back(s1.top());
            s1.push(arr1[i]);
        }
        else if(s1.size() == 0)
        {
            ans.push_back(-1);
            s1.push(arr1[i]);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" ";
}

/*

Ques :- Next Greater element to left.....
Concept:- Similar to up question..

Ques :- Next Smaller element to left...
Concept:- Similar to up

Ques :- Next Smaller to right....
Concetp:- Similar to up

*/

