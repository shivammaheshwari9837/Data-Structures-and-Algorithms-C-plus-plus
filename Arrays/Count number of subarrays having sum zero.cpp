/*

Ques :- Count number of subarrays having sum zero

*/

void work()
{
    int n;
    cin>>n;
    
    ll arr1[n+1];
    unordered_map<ll,ll> um1;
    ll sum=0,c_sub=0;
    
    for(int i=1;i<=n;++i)
    {
        cin>>arr1[i];
        sum+=arr1[i];
        
        ++um1[sum];
    }
    
    for(auto i=um1.begin();i!=um1.end();++i)
    {
        if(i->first==0)
        {
            int x=i->second+1;
            c_sub+=(x*(x-1) )/2;
        }
        else
        {
            int x=i->second;
            c_sub+=(x*(x-1))/2;
        }
    }
    cout<<c_sub;
    
    
}
