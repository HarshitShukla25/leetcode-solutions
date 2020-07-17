class Node{
	int val;
	Node *next;
}

public Node divide(Node list)
{
	if(list==NULL) return NULL;
	Node runner  = list->next;
	while(runner!=NULL)
	{
		runner = runner->next;
		if(runner==NULL) break;
		runner = runner->next;
		list=list->next;  //one pointer ek baar jump krta h aur runner wala do baarr jump krta h so that it is always at double the length far.
	}
	Node toReturn = list->next;
	list->next = NULL;
	return toReturn;
}