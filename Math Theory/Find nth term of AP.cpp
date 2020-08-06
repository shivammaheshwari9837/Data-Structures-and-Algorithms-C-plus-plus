/*

Ques :- Find nth term of AP

Concept:- Formula ---- a(nth) = a(1st term) + (n-1)*(common differnce)


*/

void work()
{
    int A,B,n;
    cin>>A>>B>>n;
    
    int diff = B - A;
    
    int ans = A + ((n-1)*diff);
    cout<<ans;
}
