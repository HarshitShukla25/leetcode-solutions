#include <bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long int
#define ull         unsigned long long int
#define pb          push_back
#define endl        '\n'
#define piil         pair<ll ,ll >
#define vi          vector<ll>
#define vpi         vector<pair<ll,ll>>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
using namespace std;

int nthugly(int n)
{
	int ugly[n];
	ugly[0]=1;
	int i2=0,i3=0,i5=0;
	int next_ugly_2 = 2;
	int next_ugly_3 = 3;
	int next_ugly_5 = 5;
	for(int i=1;i<n;i++)
	{
		ugly[i] = min(next_ugly_5,min(next_ugly_3,next_ugly_2));
		if(ugly[i] == next_ugly_2)
		{
			i2=i2+1;
			next_ugly_2 = ugly[i2]*2;
		}
		if(ugly[i] == next_ugly_3)
		{
			i3=i3+1;
			next_ugly_3 = ugly[i3]*3;
		}
		if(ugly[i] == next_ugly_5)
		{
			i5=i5+1;
			next_ugly_5 = ugly[i5]*5;
		}
	}
	return ugly[n-1] ;

}
int main()
{
    io
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
	#endif
    int n;
    cin >>n ;
   cout << nthugly(n);

	return 0;
}