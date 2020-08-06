/*

Ques :- Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T 
contains lowercase english alphabets.

Concept:- 1. using sliding window technique/two pointer
	  2. slide till some window using right pointer, than reduce one position of left pointer ,than again to find some other valid window


*/


bool toCheck(int tar[],int m1[])
{
	for(int i=0;i<=25;++i)
	{
		if(m1[i]<tar[i])
		return false;
	}
		
	return true;
}
void work()
{
	string str,tu;
	
	cin>>str>>tu;
	
	
	int tar[30]={0},m1[30]={0};
	
	for(int i=0;i<tu.size();++i)
	{
		++tar[tu[i] - 'a'];
	}
	
	int left=0,right=0;
	int pos1=-1,pos2=-1;
	int min_dis = INT_MAX;
	
	while(left<=right)
	{
		
		bool isValid = toCheck(tar,m1);
		
		if(isValid)
		{
			int temp_dis = right-left+1;
			
			if(temp_dis<min_dis)
			{
				min_dis = temp_dis;
				pos1 = left;
				pos2 = right-1;
			}
			
			char p = str[left];
			
			--m1[p-'a'];
			
			++left;
		}
		else if(right == str.size())
		{
			break;
		}
		else
		{	
			++m1[str[right]-'a'];
			
			if(right<str.size())
			++right;
		}
		
	}
	
	if(pos1 == -1)
	cout<<-1;
	else
	{
		for(int i=pos1;i<=pos2;++i)
		{
			cout<<str[i];
		}
	}
}
