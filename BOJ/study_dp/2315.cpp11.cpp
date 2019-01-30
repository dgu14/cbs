#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)
#define for1(i,p,q)                 for(int i=(int)p;i<=q;i++)
#define rfor1(i,p,q)                for(int i=(int)q;i>=p;i--)

ll n,m, d[1005], w[1005], dp[1005][1005][2], sm[1005];

ll solve(int l, int r, int c)
{
    if(dp[l][r][c]!=-1) return dp[l][r][c];

    int sl=m-l;
    int sr=m+r;

    if(sl==1 && sr==n) return dp[l][r][c]=0;

    ll nx=LONG_INF;
    if(sl!=1)
    {
        nx=min(nx, solve(l+1,r,0)+(d[(c==0?sl:sr)]-d[sl-1])*(sm[n]-(sm[sr]-sm[sl-1])));
    }

    if(sr!=n)
    {
        nx=min(nx, solve(l,r+1,1)+(d[sr+1]-d[(c==0?sl:sr)])*(sm[n]-(sm[sr]-sm[sl-1])));
    }

    return dp[l][r][c]=nx;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,n) cin>>d[i]>>w[i];
    forn1(i,n) sm[i]=sm[i-1]+w[i];

    memset(dp,255,sizeof(dp));

    cout << solve(0,0,0) << endl;

	return 0;
}
