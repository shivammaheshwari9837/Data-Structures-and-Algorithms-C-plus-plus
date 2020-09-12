/*

Ques:- Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Concept:- 1)Here we will use the concept of binary heap,ie. min Heap since we have to sort in acending order
          2)We will try to maintain the size of heap as <=K 
          
Time - O(n * K * logK)
Space - O(K)

*/

class comp
{
    public:
    bool operator()(Node *a,Node *b) //comparator function for comparing the nodes values
    {
        if(a->data <= b->data)
        return false;
        else
        return true;
    }
};
  
Node * mergeKLists(Node *arr[], int K)
{
       // Your code here
       priority_queue<Node*,vector<Node*>,comp> min_heap; //creation of minHeap
       
       Node *head = NULL,*headT = NULL;
       
       for(int i=0;i<K;++i)
       {
           if(arr[i])
           min_heap.push(arr[i]);
       }
       
       while(!min_heap.empty())
       {
            if(head == NULL) //for head node
            {
                head = min_heap.top();
                headT = head;
            }
            else
            {
                headT->next = min_heap.top();
                headT = headT->next;
            }
            
            Node *t1 = min_heap.top()->next;
            min_heap.pop();
            
            if(t1) //must not NULL 
            min_heap.push(t1);
               
       }
       
       return head;
}
