/*

Ques :-Pascal Triangle

Theory:- 1)Uses stack to store the previous state

Time - O(n)
Space - O(1)

*/

void  work()
{
    int k;
    cin>>k;
    
    if(k==1)
    cout<<1;
    else if(k==2)
    cout<<1<<" "<<1;
    else
    {
        stack<int> s1,ans;
        s1.push(1);
        s1.push(1);
        
        for(int i=3;i<=k;++i)
        {
        	while(!ans.empty())
        	{
        		ans.pop();
			}
            ans.push(1);
            while(s1.size()>1)
            {
                int temp=s1.top();
                s1.pop();
                temp+=s1.top();
                ans.push(temp);
            }
            ans.push(1);
            s1=ans;
        }
        
        while(!ans.empty())
        {
            cout<<ans.top()<<" ";
            ans.pop();
        }
    }
}

/*

Concept:- 1)Like in pascal triangle:- in some ith row they are exist iC0,iC1,iC2,....iCi

Time - O(n^2)
Space - O(1)

*/

void printPascal(int n) 
{ 
      
for (int line = 1; line <= n; line++) 
{ 
    int C = 1; // used to represent C(line, i) 
    for (int i = 1; i <= line; i++)  
    { 
          
        // The first value in a line is always 1 
        cout<< C<<" ";  
        C = C * (line - i) / i;  
    } 
    cout<<"\n";
} 
