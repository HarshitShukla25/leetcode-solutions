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
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)  for(it=x.begin();it!=x.end;it++)
 
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
/*void MatMul(ll A[N][N], ll B[N][N])
{
    ll R[N][N];
    MEM(R,0);
    REP(i, N) REP(j, N) REP(k, N) R[i][j] = (R[i][j]%mod + (A[i][k] * B[k][j])%mod)%mod;
    REP(i, N) REP(j, N) B[i][j] = R[i][j];
    return;
}
 
 
void MatPow(ll R[N][N],ll M[N][N],ll P)
{
    while(P)
    {
        if(P & 1)
            MatMul(M,R);
        MatMul(M,M);
        P = P >> 1;
    }
}*/

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
template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
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
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to check whether a string 
// is a prime number or not 
bool checkPrime(string number) 
{ 
    int num = stoi(number); 
    for (int i = 2; i * i <= num; i++) 
        if ((num % i) == 0) 
            return false; 
    return true; 
} 
  

// Driver code 
int main() 
{   io
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("finaloutput.txt", "w", stdout);
    #endif
    int k;
    cin >> k;
    int n;
    cin >>n;
    int arr[n];
    forn(i,n) cin >> arr[i];
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] >= (arr[j]+k) && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
    
    
} 
