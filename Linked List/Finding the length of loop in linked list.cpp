/*

Ques  :- Finding the length of loop in linked list..

Code Snippet:- using Floyd’s Cycle-Finding Algorithm


*/

int countNodesinLoop(struct Node *head)
{
    
    Node *fast,*slow;
    fast = head;
    slow = head;
    int counter=0;
    bool isLoop = false;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow)
        {
            Node *temp1 = slow;
            while(temp1->next!=slow)
            {
                ++counter;
                temp1=temp1->next;
            }
            isLoop = true;
            break;
        }
    }
    
    if(isLoop)
    return counter+1;
    else
    return 0;
}
