/*

Ques  :-Reverse a linked list 
Theory:- using 3 pointers..

*/

struct Node* reverseList(struct Node *head)
{
    Node *p=NULL;
    
    
    Node *q = head;
    if(q==NULL)
    return head;
    
    Node *r = head->next;
    if(r==NULL)
    {
       return head;
    }
    
    while(r!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    
    return q;
}
