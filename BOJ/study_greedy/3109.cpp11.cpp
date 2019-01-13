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

int r,c, ret, dp[10005][505];
string m[20000];

int dfs(int a, int b)
{
    if(b==c-1) return 1;

    if(a>0 && m[a-1][b+1]=='.' && dp[a-1][b+1]==0)
    {
        dp[a-1][b+1]=1;
        if(dfs(a-1, b+1)) return 1;
    }

    if(m[a][b+1]=='.' && dp[a][b+1]==0)
    {
        dp[a][b+1]=1;
        if(dfs(a, b+1)) return 1;
    }

    if(a+1<r && m[a+1][b+1]=='.' && dp[a+1][b+1]==0)
    {
        dp[a+1][b+1]=1;
        if(dfs(a+1, b+1)) return 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>r>>c;
    forn(i,r) cin>>m[i];

    forn(i,r)
    {
        ret+=dfs(i,0);
    }

    cout << ret << endl;

	return 0;
}
/*
6 5
.x.x.
...x.
..x..
.x...
.xxxx
.xxxx

*/
