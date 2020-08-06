/*

Ques :-Polynomial Addition using Linked Lists of size m and n...(Time-O(n+m), space-O(1) )..

Concept:- 1.Try to think in O(m+n) space.
	2. Than make a new single node, than just connect the links in between the nodes

*/

Node* addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    Node *head1 = p1,*head2 = p2,*ans = NULL,*ansT = NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->pow == head2->pow)
        {
            if(ans == NULL)
            {
                ans = new Node(head1->coeff + head2->coeff,head1->pow );
                ansT = ans;
            }
            else
            {
                head1->coeff+=head2->coeff;
                ansT->next = head1;
                ansT = head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->pow > head2->pow)
        {
            if(ans == NULL)
            {
                ans = new Node(head1->coeff,head1->pow);
                ansT = ans;
            }
            else
            {
                ansT->next = head1;
                ansT = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if(ans == NULL)
            {
                ans = new Node(head2->coeff,head2->pow);
                ansT = ans;
            }
            else
            {
                ansT->next = head2;
                ansT = head2;
            }
            head2 = head2->next;
        }
    }
    
    while(head1!=NULL)
    {
        ansT->next = head1;
        break;
    }
    
    while(head2!=NULL)
    {
        ansT->next = head2;
        break;
    }
    
    return ans;
}
