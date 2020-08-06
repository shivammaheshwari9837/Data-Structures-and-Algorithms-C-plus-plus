/*

Ques :- Longest valid parantheses or Longest valid substring of parantheses

Concept:-1.Managing the current maximum length using index in stack<int> DS


*/

void work()
{
    string str;
    cin>>str;
    
    stack<int> s1;
    s1.push(-1);
    
    int ans=0;
    
    for(int i=0;i<str.size();++i)
    {
    	if(str[i] == '(')
    	s1.push(i);
    	else
    	{
    		s1.pop();
    		
    		if(!s1.empty())
    		ans = max(ans,i - s1.top());
    		else
    		s1.push(i);
		}
	}
	
	cout<<ans;
    
}
