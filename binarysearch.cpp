// Simple Binary Search

l=0 r=n-1
while(l<=r)
{
	mid =l + (r-l)/2;
	if(a[mid]==target)
	return mid;
	if(a[mid]<target)
	l=mid+1;
	else 
	r= mid-1;
}
return -1;

Q. Is X a square?
take [0,x] and check m2==x

T.C. = n -> n/2 -> n/4 i.e logbase2n

Q. Find first value >=x (lower bound)

eg = x=4 in 2,3,5,6,8,10,12 gives 5

l=0,r=n-1;
ans =-1 ;
while l<=r:
	mid = l+ (r-l)/2;
	if(a[mid]>=target):
		ans= mid;
		R= mid-1
	else 
		l =mid+1;
	return ans;

Q. Rotated Array

In a rotated array find the smallest element

6,7,9,15,19,2,3

Greater smaller k maamle se nhi balki true false k hisaab se socha kro

in lower bound k cases u had something like 

F F T T T T T 
aur ab rotated me it is something like
T T T T T F F
we can also use binary search in this type

to ese dekho mid aur l ko compare krlo agr dono same i.e T T ho to mtlb to ans lie in right side

Now... find the global maximum
2,3.4.6.9,12,11,8,6,4,1
T T T T T T   F F F F F

use a[m] > a[m-1]
then ans= m
i.e ans might be this and
also do l=m+1


Find sqrt again with some precision

l=0,r=x
while(r-l>eps)
{
	mid=  l + r-l/2;
	if(mid*mid < target):
	l=mid
	else
	r=mid

}
return l + r-l /2;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while (low<high) {
            int mid=(low+high)/2;
            if (nums[mid]>nums.back()) low=mid+1;  //if(isproperty(mid))
            else high=mid;
        }
        return nums[low];
    

    }};



 while(left<right)
 {
 	int mid =left+ (right-left)/2;
 	if(istrue(mid)) {
 		right = mid;
 	}
 	else
 	 left = mid + 1;
 }
 return left/right;  left will give the last true element and right will give the first bad version