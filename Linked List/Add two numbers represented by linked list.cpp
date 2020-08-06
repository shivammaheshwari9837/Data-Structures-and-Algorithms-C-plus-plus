/*

Ques:-  Add two numbers represented by linked list

*/

struct Node * rev(Node *head)
{
    if(head->next == NULL)
    return head;
    
    Node *prev = NULL,*curr = head,*forw;
    
    while(curr!=NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    Node *p = rev(first);
    Node *q = rev(second);
    
    Node *ans,*ansT=NULL;
    
    int carry=0;
    bool fir = true;
    
    while(p!=NULL && q!=NULL)
    {
        int val = p->data + q->data;
        if(fir == true)
        {
            fir = false;
            ans = new Node((val+carry)%10);
            carry = (val + carry)/10;
            ansT = ans;
        }
        else
        {
            ansT->next = new Node((val+carry)%10);
            carry = (val + carry)/10;
            ansT = ansT->next;
        }
        p = p->next;
        q = q->next;
    }
    
    while(p!=NULL)
    {
        int val = p->data;
        ansT->next = new Node((val + carry)%10);
        carry = (val + carry)/10;
        ansT = ansT->next;
        p=p->next;
    }
    
    while(q!=NULL)
    {
        int val = q->data;
        ansT->next = new Node((val + carry)%10);
        carry = (val + carry)/10;
        ansT = ansT->next;
        q=q->next;
    }
    
    if(carry!=0)
    ansT->next = new Node(carry);
    
    ans = rev(ans);
    
    return ans;
}
