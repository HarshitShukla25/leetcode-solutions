Node* reverseLinkedList(Node* head)
{
	if(!head) return NULL;
	Node* prev= NULL,*next= NULL;
	Node* curr = head;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next =prev;
		prev = curr;
		curr = next;
	}
	Node *head_ref =prev; // one little maneavur
	return *head_ref;
}


//using recursion

void reverseLinkedList(Node* prev,Node* curr)
{
	if(!curr) return;
	if(!curr->next) //end of linked list
	{
		head =curr;
		curr->next= prev;
		return ;
	}
	reverseLinkedList(curr,curr->next);
	curr->next = prev;
}