//cycle in a linked list

Again concept of slow and fast pointer

Node* isCycle(Node* head)
{
	Node* sptr,fptr;
	sptr=fptr=head;
	while (fptr && fptr->next)
	{
	  sptr = sptr->next;
	  fptr = fptr->next;

	  if(fptr)
	  fptr->next;
	  if(sptr == fptr)
	  {
	  sptr  = head;
	  while(sptr!=fptr)
	  {
	  	sptr = sptr->next;
	  	fptr = fptr->next;
	  }
	  return sptr;
	  }
	}
}
// 5 is the junction pointer

1 -> 2 -> 3 -> 4 -> 5 -> 6
                    |     |
                   8<-  7