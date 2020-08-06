/*

Ques :- Column number to column title

*/

void work()
{
  int n;
  cin>>n;
    while(n>0)
        {
            int rem=n%26;

            if(rem==0)
            {
                ans.push_back('Z');
                n=n/26-1;
            }
            else
            {
                char temp=(rem-1)+'A';
                ans.push_back(temp);
                n/=26;
            }
    //        cout<<ans<<" ";
        }
    
}
