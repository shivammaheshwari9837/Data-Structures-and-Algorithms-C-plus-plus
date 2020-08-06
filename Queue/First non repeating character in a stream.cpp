/*

Ques :- Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a 
character is inserted to the stream. If no non repeating element is found print -1.(Time - O(2*n) )

Concept:- 1.)using queue DS
	2.) take input in queue until its frequency is 1, and than iterate queue till find a character having frequency 1 or, if queue is empty,than answer is -1

*/


void work()
{
	int n;
	cin>>n;
	
	char arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	int fre[26] = {0};
	
	char ans[n];
	queue<char> q1;
	
	for(int i=0;i<n;++i)
	{
		++fre[arr1[i]-97];
		
		if(fre[arr1[i]-97] == 1)
		q1.push(arr1[i]);
		
		if(fre[arr1[i]-97] == 2)
		{
			while((!q1.empty()) && (fre[q1.front()-97] != 1))
			{
				q1.pop();
			}
		}
		
		if(!q1.empty())
		ans[i] = q1.front();
		else
		ans[i] = '@';
	}
	
	for(int i=0;i<n;++i)
	{
		if(ans[i] == '@')
		cout<<-1<<" ";
		else
		cout<<ans[i]<<" ";
	}
}
