/*

Ques:- Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and 
such that the order of linked list is sustained.

Concept:- 1)If next element is expected to be greater, but is smaller, swap current with next.
          2)if next element is expected to be smaller, but is larger, swap current with next.
          3)his swapping wont affect the sorted sequence before the current node.
          
Time - O(n)
Space - O(1)

*/

Node *zigZag(Node* head)
{
 // your code goes here
    if(!head->next)
    return head;
    
    Node *curr = head,*nxt = head->next;
    bool isSmall = true;
    
    while(nxt != NULL)
    {
        if(isSmall) //has to be small
        {
            if(curr->data > nxt->data) //but here is big,swap the data
            {
                swap(curr->data,nxt->data);
            }
        }
        else //has to larger
        {
            if(curr->data < nxt->data) //but appear to be small,swap the data
            {
                swap(curr->data,nxt->data);
            }
        }
        
        isSmall = !isSmall; //switching between large/small
        curr = curr->next;
        nxt = nxt->next;
    }
    
    return head;
}
