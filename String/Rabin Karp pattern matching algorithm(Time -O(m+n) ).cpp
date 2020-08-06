/*

Ques :- Rabin Karp pattern matching algorithm(Time -O(m+n) )

Concept:- 1.)We will using the rolling hash function technique
	2.) We will use base number as a prime number to create a good hash function

*/

ll createHash(string str,int n)
{
	ll res = 0;
	for(int i=0;i<n;++i)
	{
		res+= (ll)((ll)str[i]*(ll)pow(prime,i));
	}
	
	return res;
}

ll newHash(string str,ll oldHash,ll oldIndex,ll newIndex,ll n)
{
	oldHash -= str[oldIndex];
	oldHash /= prime;
	oldHash += (ll)( (ll)str[newIndex]*(ll)pow(prime,n-1) );
	
	return oldHash;
}

bool check(string str1,string str2,ll st1,ll end1,ll st2,ll end2)
{
	if(end1-st1 != end2-st2)
	return false;
	
	while(st1<=end1 and st2<=end2)
	{
		if(str1[st1] != str2[st2])
		return false;
		
		++st1;
		++st2;
	}
	
	return true;
}


void work()
{
	string str,patt;
	
	cin>>str>>patt;
	
	ll strHash,pattHash;
	
	strHash = createHash(str,patt.length());
	pattHash = createHash(patt,patt.length());
	
	for(int i=0;i<=str.length()-patt.length();++i)
	{
		if(strHash == pattHash and check(str,patt,i,i+patt.length()-1,0,patt.length()-1))
		{
			cout<<i;
			return;
		}
		else 
		{
			strHash = newHash(str,strHash,i,i+patt.length(),patt.length());
		}
	}
	
	cout<<-1;
	
}
