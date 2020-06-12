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
ll fact(ll n) 
{
    return (n==1 || n==0) ? 1: n * fact(n - 1);  
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 

#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SLL(a) scanf("%lld",&a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define SS(a) scanf("%s",a)
#define SC(a) scanf("%c",&a)
#define SD(a) scanf("%lf",&a)

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u-1].pb(v-1);
	adj[v-1].pb(u-1);
}

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
} 
void SieveOfEratosthenes(int n, bool prime[]) 
{ 
    
    for (int i = 2; i <= n; i++) 
        prime[i] = true;
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 

} 
string s="ABCD";
int tetra(int t,char c)
{
   int r=0;
   if(c=='D' && t==0)
   	return 0;
   else
   {
   	for(int i=0;i<s.size();i++)
   	{
   		if(s[i]!=c)
   			r += tetra(t-1,s[i]);
   	}
   	return r+1;
   }
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
	ll t;
	cin >> t;
	int res = tetra(t,'D');
	cout << res;
}