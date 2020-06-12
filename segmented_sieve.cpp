#include<bits/stdc++.h>
using namespace std;
void simpleSieve(int n)
{
	bool mark[n];
	memset(mark,true,sizeOf(mark));
	for(int p=2 ; p*p < n ; p++)
	{
		if(mark[p]==true)
		{
			for(int i=p*2; i< n; i+=p)
				mark[i]=false;
		}
	}
}