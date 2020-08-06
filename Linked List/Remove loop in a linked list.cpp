/*

Ques 19:-Remove loop in a linked list(Time-O(n), space-O(1) )

Steps:- 1.)Find if there is a cycle via hare-tortoise alogo
	2.)Main motto is to find the junction point of cycle, as node just previous to junction point is our target node of which we have to do----:- next->NULL
	3.) For junction point, make a node with head and another to meeting point(while findind the cycle), than increase both with same rate, and thus junction will be find
  
  */
  
  void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    
    Node* p = head;
    Node* q = head;
    Node* temp;
    while(q && q->next){
        temp = p;
        p=p->next;
        q=q->next->next;
        if(p==q)
            break;
    } 
    if(p==q){
        p = head;
        while(p!=q){
            p=p->next;
            temp = q;
            q=q->next;
        }
        temp->next=NULL;
    }
}
