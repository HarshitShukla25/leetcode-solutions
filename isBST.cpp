private class Node{
	int value;
	Node *right;
	Node *left;
}

public bool isBST(Node n)
{
	return isBSThelp(n,INT_MIN,INT_MAX);
}

public bool isBSThelp(Node n,int min,int max)
{
	if(n==NULL) return true;
	if(n.value < min || n.value > max) return false;
	return isBSThelp(n->left,min,n.value) && isBSThelp(n->right,n.value+1,max);
}