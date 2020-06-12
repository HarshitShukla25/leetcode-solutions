//Declaration of Heap
struct Heap
{
	int *arr;
	int count;
	int capacity;
	int heap_type;
};
//Creating Heap
Heap *createHeap(int capacity,int heap_type)
{
	Heap *h= (struct Heap *)malloc(sizeof(struct Heap));
    if(h == NULL)
    {
    	printf("Memory Error\n");
    }
    h->heap_type = heap_type;
    h->capacity = capacity;
    h->count = 0;
    h->arr = (int *)malloc(sizeof(int)*h->capacity);
    if(h->arr = NULL)
    	{
    		printf("Memory Error\n");
    		return;
    	}
    return h;
}
//Location of Parent of Node
int parent(struct Heap *h, int i)
{
	if(i<=0 || i>= h->count)
		return -1;
	return (i-1)/2;
}
//Children of Node
int leftChild(struct Heap *h,int i)
{
	int left = 2*i+1;
	if(left >= h->count)
      return -1;
	return left;
}
int rightChild(struct Heap *h,int i)
{
	int right = 2*i+2;
	if(right >= h->count)
      return -1;
	return right;
}
//Maximum which is the first element of the array
int getMax(Heap *h)
{
	if(h->count == 0 )
		return -1;
	return h->arr[0];
}
//Heapyfing an element
//Percolate down
void percolateDown(struct Heap *h,int i)      //But where is the base case ??
{
	int l,r,max,temp;
	l=leftChild(h,i);
	r=rightChild(h,i);
	if(l!=1 && h->arr[l] > h->arr[i])
		max = l;
	else
		max = i;
	if(r!=1 && h->arr[r] > h->arr[i])
		max =r;
	if(max != i)
	{
		swap(h->arr[max],h->max[i]);
	}
	percolateDown(h,max);
}
//Deleting an element (just delete from the root and heapify it again)
int deleteMax(Heap *h)
{
	int data;
	if(h->count == 0)
		return -1;
	data = h->arr[0];
	h->arr[0] = h->arr[h->count-1]; //copying the last element as the root and then
	h->count--;                     //deleting it
	percolateDown(h,0);         //heapify again
	return data;
}
//Inserting an element
//Increase heap size-----keep new element at end if tree -- heapify 
int insert(Heap *h,int data)
{
	int i;
	if(h->count == h->capacity)
		ResizeHeap(h);
	h->count++;
	i=h->count-1;
	while(i>=0 && data > h->arr[(i-1)/2])   //if parent's value is less than data then shift i to the parent's location
	{
		h->arr[i] = h->arr[(i-1)/2];
		i=(i-1)/2;

	}
	h->arr[i]=data;
}
void ResizeHeap(Heap *h)
{
	int *arr_old = h->arr;
	h->arr = (int *)malloc(sizeof(int)*h->capacity*2);  //doubling the capacity
    if(h->arr == NULL)
    	{
    		printf("Memory Error\n");
    		return;
    	}
    for(int i=0;i< h->capacity ;i++)
    	h->arr[i] = arr_old[i];
    h->capacity * =2;
    free(arr_old);    //Freeing the temp array
 }
 //Destroy Heap
 void destroyHeap(struct Heap *h)
 {
 	if(h==NULL)
 		return;
 	free(h->arr);
 	free(h);       //What is the difference between free(h) and h=NULL
 	h=NULL;      
 }
//Building a Heap
 void BuildHeap(struct Heap *h,int A[],int n)
{
	if(h==NULL)
		return;
	while(n>h->capacity)
	   ResizeHeap(h);
	for(int i=0;i<n;i++)
		h->arr[i] = A[i];
	h->count = n;
	for(int i=(n-1)/2;i>=0;i--) //since leaf nodes are always heaified so we start from parent nodes
		percolateDown(h,i);
}
//Heap Sort
void heapsort(int A[],int n) //insert all element into heap, remove then from root of heap until heap is empty,
//instead of deleting exchange the first and the last element and reduce the count size
{
	Heap *h = createHeap(n);
	int old_size,i,temp;
	BuildHeap(h,A,n);
	old_size = h->count;
	for(int i=n-1;i>0;i--)
	{
		//h->arr[0] is the largest element
		swap(h->arr[0],h->arr[count-1]);
		h->count--;
		percolateDown(h,0);
	}
	h->count = old_size;
}  //Since the TC of both the insertion and deletion is O(log n) thus TC for heap sort of n elements is O(nlogn).