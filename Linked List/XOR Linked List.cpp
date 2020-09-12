/*

Ques:- https://practice.geeksforgeeks.org/problems/xor-linked-list/1

Concept:- 1)currNode->npx = (prev)^(next)
          2)For next pointer,we can do---> (npx^prev) ie...(prev^next)^prev = next
          3)Similar for previous pointer
          
          

*/

// function should insert the data to the front of the list
struct Node* insert(struct Node *head, int data)
{
	// Code her
	Node *t1 = new Node(data);
	t1->npx = XOR(head,NULL);
    
    if(head) //have to do to handle if head == NULL,ie. first node to be inserted ....
    { 
        Node *temp = XOR(head->npx,NULL);
        head->npx = XOR(t1,temp);
    }
	
	return t1;
	
}

// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head)
{
	Node *t1 = head,*prev = NULL,*temp = NULL;

	//backward printing...
	while(t1 != NULL)
	{
	    cout<<t1->data<<" ";
	    temp = t1;
	    t1 = XOR(t1->npx,prev);
	    prev = temp;
	}
	
	cout<<"\n";
	
	//forward printing.......
	t1 = prev;
	prev = NULL;
	while(t1 != NULL)
	{
	    cout<<t1->data<<" ";
	    temp = t1;
	    t1 = XOR(t1->npx,prev);
	    prev = temp;
	}
	
}
