/*

Ques:- Find x^n

Concept:- 1)Using the binary exponentiaion

Time - O(log n)
Space - O(1)

*/

#define ll long long

ll binary_exp(ll a,ll n)
{
	ll res=1;

	while(n)
	{
		if(n%2==0)
		{
// 			a*=a;
            a=(a*a)%MOD;
			n/=2;
		}
		else
		{
// 			res*=a;
            res=(res*a)%MOD;
			--n;
		}
	}
	return res%MOD;
}

