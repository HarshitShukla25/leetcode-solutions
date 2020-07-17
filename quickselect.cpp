int kth_smallest(int arr[],int l, int r,int k)
{	if(k>0 && k<=r-l+1)
	{
			int index = partition(arr,l,r);
			if(index -l == k-1)
				return arr[index];
			if(index -l > k-1)
				return kth_smallest(arr,l,index-1,k);
			return kth_smallest(arr,index+1,r.k-index+l-1);
	}
	return INT_MAX;
}
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 