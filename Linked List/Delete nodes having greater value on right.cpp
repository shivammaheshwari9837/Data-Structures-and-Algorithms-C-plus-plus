/*

Ques:- Given a singly linked list, remove all the nodes which have a greater value on its next adjacent element.

Concept:- 1)First reverse the linked list
          2)Than take a variable that stores the current maximum
          3)CurrentNode->data >= maximum,connect the node with previous node
          4)Than again reverse the nodes(aka Linked List)
          
 Time - O(n)
 Space - O(1)

*/

Node* rev(Node* head) //simply reverse 
{
    if(head == NULL)
    return head;
    
    Node *p = NULL,*q = head,*r = NULL;
    
    while(q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

Node *compute(Node *head)
{
    // your code goes here
    Node* rev1 = rev(head);
    Node *rev1T = rev1,*end = rev1->next;
    
    int maxi = rev1->data;
    
    while(end != NULL)
    {
        int val = end->data;
        
        if(val >= maxi) //if valid ,than only connect the node with tail linked list of final answer
        {
            rev1T->next = end;
            rev1T = rev1T->next;
        }
        
        
        maxi = max(maxi,val);
        end = end->next;
    }
    
    rev1T->next = NULL; //remember to apply null 
    
    Node *ans = rev(rev1);
    
    return ans;
}
