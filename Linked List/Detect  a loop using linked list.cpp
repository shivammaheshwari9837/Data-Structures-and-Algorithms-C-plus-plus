/*

Ques :- Detect  a loop using linked list(T= O(n) )

Method 1:- Using hashing..

*/

bool detectLoop(Node* head)
{
    // your code here
    
    unordered_map<Node *,int> m1;
    bool ans=false;
    
    Node *temp1=head;
    
    while(temp1->next!=NULL)
    {
        if(m1.find(temp1)!=m1.end())
        {
            ans=true;
            break;
        }
        ++m1[temp1];
        temp1=temp1->next;
    }
    
    return ans;
}

/*

Method 2:- Floyd’s Cycle-Finding Algorithm

  Theory:-
  1. This is the fastest method and has been described below:

  2. Traverse linked list using two pointers.
  3. Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
  4. If these pointers meet at the same node then there is a loop. If pointers do not meet then linked 
  list doesn’t have a loop.

*/
