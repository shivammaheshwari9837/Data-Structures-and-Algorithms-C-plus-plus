/*

Ques :- Largest number form from an array:-

Concept:- 1.) Take two numbers(left X and Y) and, check ((X concat Y) < (Y concat X))

*/

bool comp(int x,int y)
{
    string X = to_string(x);
    string Y = to_string(y);
    
    string XY = X+Y;
    string YX = Y+X;
    
    return XY.compare(YX) > 0 ? 1 : 0;
}


void work()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    
    for(int i=0;i<n;++i)
    {
        cin>>v1[i];
    }
    
    sort(v1.begin(),v1.end(),comp);
    
    
    for(int i=0;i<n;++i)
    cout<<v1[i];
}
