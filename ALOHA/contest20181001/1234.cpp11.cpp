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

ll N,A,B,C;
ll dp[12][60][60][60];
ll fact[12];

ll solve(ll n, ll a, ll b, ll c)
{
    if(n==0) return 1;
    if(dp[n][a][b][c]!=-1) return dp[n][a][b][c];
    // one color,
    // two color, n must even
    // 3 color, n must divided by 3

    ll ret=0;
    if(a>=n) ret+=solve(n-1,a-n,b,c);
    if(b>=n) ret+=solve(n-1,a,b-n,c);
    if(c>=n) ret+=solve(n-1,a,b,c-n);

    if(n%2==0)
    {
        if(a>=n/2 && b>=n/2) ret+=solve(n-1, a-n/2, b-n/2,c) * ((fact[n]/fact[n/2])/fact[n/2]);
        if(a>=n/2 && c>=n/2) ret+=solve(n-1, a-n/2, b, c-n/2) * ((fact[n]/fact[n/2])/fact[n/2]);
        if(b>=n/2 && c>=n/2) ret+=solve(n-1, a, b-n/2,c-n/2) * ((fact[n]/fact[n/2])/fact[n/2]);
    }

    if(n%3==0)
    {
        if(a>=n/3 && b>=n/3 && c>=n/3) ret+=solve(n-1, a-n/3, b-n/3, c-n/3) * (((fact[n]/fact[n/3])/fact[n/3])/fact[n/3]);
    }

    return dp[n][a][b][c]=ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>A>>B>>C;
    forn(i,12) forn(j,60) forn(k,60) forn(r,60) dp[i][j][k][r]=-1;
    fact[0]=1; forn1(i,11)fact[i]=fact[i-1]*i;
    A=min(55ll, A); B=min(55ll, B); C=min(55ll, C);

    cout << solve(N,A,B,C) << endl;

	return 0;
}

