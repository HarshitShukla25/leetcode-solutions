class Solution {
public:
	#define a nums
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=a.size()-1;
        while(m<=h) //<= is imp
        {
        	if(a[m]==0)
        	{
        		swap(a[m],a[l]);
        		l++; //increase the l pointer taki agle swap me next jagah pe 0 aae.
        		m++;
        	}
        	else if(a[m]==1) // dont use if if if galat ho jaega since ek pos ko ek hi cheez k lie process krna h
        	{
        		m++; //skip that thing since automatically aa jaega beech me
        	}
        	else 
        	{
        		swap(a[m],a[h]);
        		h--;
        		//isme m++ islie nhi krenge kyuki h-- krne pe ek nayi value ai h m ki jagah pe jisko hmne process nhi kia h abhi.
        	}
        }
    }
};