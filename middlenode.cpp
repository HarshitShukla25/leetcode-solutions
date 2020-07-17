//Middle Node

Node* find_mid(Node *head)
{
	if(!head) return NULL;
	Node *sptr,*fptr;
	sptr = fptr =head;
	while(fptr && fptr->next)
	{
	sptr =sptr->next;
	fptr =fptr->next;
	if(fptr)
	fptr = fptr->next;
	}

	return sptr;
}