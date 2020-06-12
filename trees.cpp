struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
//Uses - huffman coding trees, bst search insertion deletion , priority queue 
//Pre In Post DLR LDR LRD
//Level order traversal
void preOrder(BinaryTreeNode *root){     //Recursive
	if(root){
		printf("%d",root->data);
 		preOrder(root->left);
 		preOrder(root->right);
	}
}
void preOrderNonRecursive(BinaryTreeNode *root){  //TC = O(n)  SC = O(n)
	Stack *S= CreateStack();
	while(true)
	{
		while(root)
		{
			printf("%d",root->data);
			Push(S,root);
			root = root->left;
		}
		if(isEmptyStack(S))
		{
			break;
		}
		root = Pop(S);
		root =root->right;
	}
	DeleteStack(S);
}
void inOrder(BinaryTreeNode *root){
	if(root){
		inOrder(root->left);
		printf("%d",root->data);
		inOrder(root->right);
	}
}
void inOrderNonRecursive(BinaryTreeNode *root){  //TC = O(n)  SC = O(n)
	Stack *S= CreateStack();
	while(true)
	{
		while(root)
		{
			Push(S,root);
			root = root->left;
		}
		if(isEmptyStack(S))
		{
			break;
		}
		root = Pop(S);
		printf("%d",root->data);
		root =root->right;
	}
	DeleteStack(S);
}
void postOrder(BinaryTreeNode *root){
	if(root){
		inOrder(root->left);
		inOrder(root->right);
		printf("%d",root->data);
	}
}
//Post Order - non recursive dekh lena
//LEVEL ORDER TRAVERSAL
void levelOrderTraversal(BinaryTreeNode *root){
	BinaryTreeNode *temp;
	Queue *Q = CreateQueue();
	if(!root)
	  return;
	EnQueue(Q,root);
	while(!isEmptyQueue(Q))
	{
		temp = DeQueue(Q);
		printf("%d",temp->data);
		if(temp->left)
			EnQueue(Q,temp->left);
		if(temp->right)
			EnQueue(Q,temp->right);

	}
	DeleteQueue();
}
//max element of Binary tree
int findMax(BinaryTreeNode *root){
	int left,right,root_val,max=INT_MIN;
	if(!root)
	{	root_val=root->data;
		left = findMax(root->left);
		right = findMax(root->right);
		if(left>right)
			max=left;
		else
			max=right;
		if(root_val > max)
			max = root_val;
	}
	return max;
}
//also do it without recursion
//SEARCH
int search(BinaryTreeNode *root,int val){
	int temp;
	if(root==NULL)
		return 0;
	else
	{
		if(val == root->data)
			return 1;
		temp = search(root->left,val);
		if(temp!=0)
			return temp;
		else
		return search(root->right,val); 
	}
	return 0;
}
//also without recursion
//inserting an element in a tree
void insertBinarySearch(BinaryTreeNode *root,int val)
{
	Queue *q;
	BinaryTreeNode *temp;
	BinaryTreeNode *newNode;
	newNode =(struct BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	newNode->left =NULL;
	newNode->right=NULL:
	if(!newNode){
		printf("Memory Error\n");
		return;
	}
	if(!root)
	{
		root =newNode;
		return;
	}
	Q = CreateQueue();
	EnQueue(Q,root);
	while(!isEmptyQueue(Q))
	{
		temp = DeQueue(Q);
		if(temp->left)
		{
			EnQueue(Q,temp);
		}
		else
		{
			temp->left =newNode;
			DeleteQueue();
			return;
		}
		if(temp->right)
		{
			EnQueue(Q,temp);
		}
		else
		{
			temp->right =newNode;
			DeleteQueue();
			return;
		}
	}
	DeleteQueue(Q);

}
//Size of Binary Tree=no. of nodes in bt
int sizeofBT(BinaryTreeNode *root)
{
	if(root==NULL)
		return 0;
	return 1+sizeofBT(root->left)+sizeofBT(root->right);
}
//deleting the whole tree
void deleteBT(BinaryTreeNode *root)
{
	if(root ==NULL)
		return ;
	deleteBT(root->left);
	deleteBT(root->right);
	free(root);
	//first delete the subtrees
}
int heightOfBT(BinaryTreeNode *root)
{
	if(root==NULL)
		return 0;
	return 1+max(heightOfBT(root->left),heightOfBT(root->right));
}
//height of tree using level order traversal
int heightOfBT_nr(BinaryTreeNode *root)
{
	int level =0;
	Queue *Q;
	if(root==NULL)
		return 0;
	EnQueue(Q,root);
	//end of first level
	EnQueue(Q,NULL);
	while(!isEmptyQueue(Q))
	{
        root = DeQueue(Q);
        //completion of current level
		if(root == NULL)
		{ //put another marker for next level
			if(!isEmptyQueue(Q))
				EnQueue(Q,NULL);
			level++;

		}
		else
		{
			if(root->left)
				EnQueue(Q,root->left);
			if(root->right)
				EnQueue(Q,root->right);
		}
	}
	return level;
}
//deepest node
BinaryTreeNode *deepestNodeBT(BinaryTreeNode *root)
{
	BinaryTreeNode *temp;
	Queue *Q;
	if(!root) return NULL;
	Q = CreateQueue();
	EnQueue(Q,root);
 	while(!isEmptyQueue(Q))
 	{
 		temp = DeQueue(Q);
 		if(temp->left)
 			EnQueue(temp->left);
 		if(temp->right)
 			EnQueue(temp->right);

 	}
 	DeleteQueue(Q);
 	return temp;
}
/*deleting an element from Binary Tree
 -starting at root find the node that is t0 be deleted
 -find the deepest node of the tree
 -replace the deepest node with the data to be deleted
 -delete the deepest node
*/
//finding the number of leaves without recursion
int noofleaves_nr(BinaryTreeNode *root)
{
	int count;
	Queue *Q;
	BinaryTreeNode *temp;
	if(!root) return 0;
	Q = CreateQueue();
	EnQueue(Q,root);
	while(isEmptyQueue(Q))
	{
		temp = DeQueue(Q);
		if(!temp->left && !temp->right)
			count++;
		else
		{
			if(temp->left)
				EnQueue(temp->left);
			if(temp->right)
				EnQueue(temp->right);
		}
	}
	DeleteQueue(Q);
	return count;
}
//full nodes without recursion
// just replace line 262 with if(temp->left && temp->right)
//half nodes if(temp->left && !temp->right || !temp->left && temp->right)

//Compare two binary trees if they are structurally equal
// if both trees null then same
//if not, compare data and compare left and right subtree
int compareBT(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	if(roo1==NULL && root2 == NULL)
		return 1;
	if(root1==NULL || root2 ==NULL)
		return 0;
	return (root1->data == root2->data && compareBT(root1->left,root2->left) && compareBT(root1->right,root2->right));
}
//diameter of binary tree-longest path between two leaves of a tree
// first calculate the the diameter of left subtree then right subtree send max val +1
int diameterBT(BinaryTreeNode *root,int *ptr)
{
	int left,right;
	if(!root)
		return 0;
	left =diameterBT(root->left,ptr);
	right = diameterBT(root->right,ptr);
	if(left+right > *ptr)                   //easily forgettable
		*ptr =left+right;           
	return max(left,right)+1;            
}
int diameterBT_alt(BinaryTreeNode *root)
{
	if(!root) return 0;
	int ldiameter =diameterBT_alt(root->left);
	int rdiameter =diameterBT_alt(root->right);
	int lheight = heightOfBT(root->left);
	int rheight = heightOfBT(root->right);
	return max(lheight+rheight+1,max(ldiameter,rdiameter)); //????????
}
//finding the level which has the maximum sum in the binary tree
int levelwithmaxsumBT(BinaryTreeNode *root)
{
	BinaryTreeNode *temp;
	int level=0;
	int max_level-0;
	int curr_sum=0;
	int max_sum_level=0;
	if(!root) return 0;
	Queue *Q;
	Q = CreateQueue(Q);
	EnQueue(Q,root);
	EnQueue(Q,NULL);
	while(!isEmptyQueue(Q))
	{
		temp =DeQueue(Q);
		if(temp==NULL)
		{   
			
			if(max_sum_level<curr_sum)
			{
				max_sum_level = sum;
				max_level = level;
			}
			curr_sum=0;
			//place the indicator for the next level at the end of the queue      (NOT UNDERSTOOD)
			if(!isEmptyQueue(Q)) EnQueue(Q,NULL);

			level++;
		}
		else
		{
			curr_sum+=temp->data;
			if(temp->left) EnQueue(Q,temp->left);
			if(temp->right) EnQueue(Q,temp->right);
		}
	}
	return max_level;
}
//checking the existence of a path with a given sum;
void printPathsRecur(BinaryTreeNode *root,int path[],int pathLen)
{
	if(root==NULL) return;
	path[pathLen]=root->data;
	pathLen++;
	if(root->left==NULL && root->right == NULL)
		PrintArray(path,pathLen);
	else
	{
		printPathsRecur(root->left,path,pathLen);
		printPathsRecur(root->right,path,pathLen);
	}
}
void PrintArray(int path[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d",path[i]);
	}

}
//sum of all elements of the tree
int addBT(BinaryTreeNode *root)
{
	if(!root) return 0;
	else
		return root->data + addBT(root->left)+addBT(root->right);
}
//also do it without recursion

//Mirror tree
BinaryTreeNode *mirrorBT(BinaryTreeNode *root)
{   BinaryTreeNode *temp;
	if(root)
	{
		mirrorBT(root->left);
		mirrorBT(root->right);
 		temp = root->left;
 		root->left =root->right;
 		root->right= temp;
	}
	return root;
}
//check whether two trees are mirror of each other
int areMirrorsBT(BinaryTreeNode *root1,BinaryTreeNode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;
	else
		return areMirrorsBT(root1->left,root2->right) && areMirrorsBT(root1->right,root2->left); //easily forgettable
}

