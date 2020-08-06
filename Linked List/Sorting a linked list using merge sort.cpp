/*

Ques :- Sorting a linked list using merge sort

Concept:- 1.)similar to merge sort

*/


ListNode* merge(ListNode *l1,ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);
        
        return merge(left_side,right_side);
        
    }
