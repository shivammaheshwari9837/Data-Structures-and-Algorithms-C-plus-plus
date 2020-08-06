/*

Ques :-Reorder Linked List in O(n) time and O(1) space.... 

PS:- Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3->NULL


Intitution:- 1.)Split the list into 2 halves.
    	2.) Next reverse the second half.
	3.)Now, merge the 2 halves while picking elements alternatively from each half.
  
  */
  
  Node* rev(Node *head)
    {
        if(head == NULL || head->next == NULL)
        return head;

        Node *p=NULL;
        Node *q = head,*r=NULL;

        while(q!=NULL)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        return p;
    }
    
    void merge(Node *l1,Node *l2)
    {
        while(l1!=NULL)
        {
            Node *l1_next = l1->next;
            Node *l2_next = l2->next;
            
            l1->next = l2;
            
            if(l1_next == NULL)
                break;
            
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }

void reorderList(Node* head) {
       // Your code here
            if(head == NULL || head->next == NULL)
            return;
        
        //head of first half..
        Node *l1 = head;
        //head of second half;
        Node *slow = head;
        //tail of second half
        Node *fast = head;
        //tail of first half
        Node *prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        Node *l2 = rev(slow);
        merge(l1,l2);
}
