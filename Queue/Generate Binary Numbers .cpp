/*

Ques:- Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Concept:-  1)Use a queue and push 1 in it. 
           2)Now while n-- is not zero keep on popping and printing the output. Now, append 1 and 0 to the output and push in the queue and keep repeating the same.
           
Time - O(n)
Space - O(n)

*/

void work()
{
    int n;
    cin>>n;
    
    queue<string> q1;
    q1.push("1");
    
    while(n--)
    {
        string str = q1.front();
        q1.pop();
        
        cout<<str<<" ";
        q1.push(str+"0");
        q1.push(str+"1");
    }
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}
