/*

Ques 7:- Clone a linked list or Copy list with random pointer(leetcode)

Method 1:- Time=O(n), Space- O(n)
Intitution:- 1.) Double hashing

*/


Node* copyRandomList(Node* head) {
        
        unordered_map<int,Node*> m1;
        unordered_map<Node*,Node*> m2;
        Node *p=head;
        
        
        Node *q = NULL,*qT=NULL;
        
        while(p!=NULL)
        {
            if(q == NULL)
            {
                q = new Node(p->val);
                qT = q;
                m2[p] = qT;
            }
            else
            {
                qT -> next = new Node(p->val);
                qT = qT->next;
                m2[p] = qT;
            }
            p = p->next;
        }
    
        
        p = head;
        int index=-1;
        while(p!=NULL)
        {
            ++index;
            m1[index] = p->random;
            p = p->next;
        }
        
        p=head;
        
        p = q;
        index=-1;
        while(p!=NULL)
        {
            ++index;
            Node *temp1 = m2[m1[index] ];
            p->random = temp1;
            p = p->next;
        }
        
        return q;
        
    }
