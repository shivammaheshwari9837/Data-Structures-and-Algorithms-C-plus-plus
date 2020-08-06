/*

Ques :- The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Theory:- 1. finding the first buy stock as smallest possible in a  strictly decreasing range
2. After range find the larget in a strictly increasing range

*/

void work()
{
    int n,buy,sell,i,j,index2,index1;
    cin>>n;
    
    int v1[n];
    
    vector<pair<int,int> > ans;
    
    for(int i=0;i<n;++i)
    cin>>v1[i];
    
    buy=v1[0];
    index1=0;
    
//    cout<<buy;
    
    for(i=1;i<n;)
    {
//    	cout<<i<<"\n";
        if(buy>v1[i])
        {
            buy=v1[i];
            index1=i;
            ++i;
        }
        else if(buy<v1[i])
        {
            // sell=v1[i];
            sell=0;
            j=i;
            
            index2=i;
            
            for(;j<n&& v1[j]>buy;++j)
            {
            	if(v1[j]>sell)
            	{
            		index2=j;
            		sell=v1[j];
				}
				else
				break;
			}
            
            ans.push_back({index1,index2});
            
            index1=index2+1;
            buy=v1[index1];
            i=index1+1;
        }
    }
    
    if(ans.size()==0)
    cout<<"No Profit";
    else
    {
    	for(int i=0;i<ans.size();++i)
	    {
	    	cout<<"("<<ans[i].first<<" "<<ans[i].second<<") ";
		}
	}
}
