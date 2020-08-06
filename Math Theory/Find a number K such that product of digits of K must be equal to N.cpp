/*

Ques :-Given a number N. Find a number K such that product of digits of K must be equal to N.(K must be samllest as poosible)

Instituion:- 1.)Since digit cant be greator than 9,we will only find some factors form i=2 to  i=9.
	    2.) since K must be smallest possible,thus divide N from (i<=9 && i>=2), and print it

*/

bool prime(ll N,vector<ll> &temp)
{
    
    for(ll i=9;i>=2;--i)
    {
        while(N % i == 0)
        {
            temp.push_back(i);
            N/=i;
        }
    }
    
    if(N>1)
    return false;
    else
    return true;
    
}

void work()
{
    ll N;
    cin>>N;
    
    if(N == 1)
    {
        cout<<1;
        return;
    }
    
    vector<ll> primeFact;
    
    bool isCheck = prime(N,primeFact);
    
    if(!isCheck)
    {
        cout<<-1;
        return;
    }
    
    for(int i=primeFact.size()-1;i>=0;--i)
    cout<<primeFact[i];
}
