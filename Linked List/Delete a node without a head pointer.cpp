/*

Ques 12:- Delete a node without a head pointer.....time(O(1) ) and space - O(1) 

Concept:- 1.)Copy the data of next node to the current node. Then, link the node after the next node to the current node. 
This way, next node is removed but its data is saved in the current node.

*/

void deleteNode(Node *node)
{
	if(!node->next)
		return;
		// if this the last node of list, it cannot be deleted
	
	Node* del = node->next;
	// next node will be freed
	
	node->data = del->data;
	// copying data of next node
	
	node->next = del->next;
	// bypassing the next node
	
	free(del);
	// freeing memory
}
