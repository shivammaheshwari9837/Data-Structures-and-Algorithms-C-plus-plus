/*

Ques  :- Intersection Point in Y Shapped Linked Lists

Theory:-There are many methods to solve this problem.
Method Using difference of node counts:

1) Get count of the nodes in the first list, let be c1.
2) Get count of the nodes in the second list, let be c2.
3) Get the difference of counts d = abs(c1 – c2)
4) Now traverse the bigger list from the first node till d nodes so that from here onwards 
both the lists have equal no of nodes.
5) Then we can traverse both the lists in parallel till we come across a common node

*/


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp1=head1;
    int coun1=0,coun2=0;
    
    while(temp1!=NULL)
    {
        ++coun1;
        temp1=temp1->next;
    }
    
    temp1=head2;
    
    while(temp1!=NULL)
    {
        ++coun2;
        temp1=temp1->next;
    }
    
    int diff=abs(coun1-coun2);
    
    Node *small,*lar;
    
    if(coun1>coun2)
    {
        lar = head1;
        small = head2;
    }
    else 
    {
        lar = head2;
        small = head1;
    }

    
    while(diff>0)
    {
        --diff;
        lar=lar->next;
    }
    
    int node=-1;
    while(small!=NULL)
    {
        if(small == lar)
        {
            node = small->data;
            break;
        }
        small = small->next;
        lar = lar->next;
    }
    
    return node;
}
