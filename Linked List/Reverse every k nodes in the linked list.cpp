/*

Ques :- Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

*/

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    
    node *prev = NULL;
    node *curr = head;
    node *forw;
    
    int coun = k;
    
    while(coun-- && curr!=NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    
    if(head!=NULL) head->next = reverse(forw,k);
    return prev;
}
