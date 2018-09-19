#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

int n,m, sz[1000], dp[1000][1000], tdp[1000];
V<int> adj[1000];

void mrg(int u, int v)
{
    forn(i,sz[u]+sz[v]) { if(i<sz[u]) tdp[i]=dp[u][i]+1; else tdp[i]=INF; }

    forn(i,sz[u])
    {
        forn(j,sz[v])
        {
            tdp[i+j+1]=min(tdp[i+j+1], dp[u][i]+dp[v][j]);
        }
    }

    forn(i,sz[u]+sz[v]) dp[u][i]=tdp[i];
}

void dfs(int src, V<bool>& vst)
{
    vst[src]=true; dp[src][0]=0; sz[src]++;

    for(int there:adj[src])
    {
        if(!vst[there]) dfs(there, vst), mrg(src, there), sz[src]+=sz[there];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m; int a,b;
    forn(i,n-1) cin>>a>>b, adj[a].push_back(b), adj[b].push_back(a);

    forn(i,1000) forn(j,1000) dp[i][j]=INF;
    V<bool> vst(1000, false); dfs(1, vst);

    int min_c=INF;
    forn1(i,n)
    {
        if(i==1) min_c=min(min_c, dp[1][m-1]);
        else min_c=min(min_c, dp[i][m-1]+1);
    }

    cout << min_c << endl;

	return 0;
}

