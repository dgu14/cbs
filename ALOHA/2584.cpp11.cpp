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

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

int n,k, sz[1050];
V<V<ii>> adj[1050];
int dp[1050][1050];

int dfs(int src, V<bool>& vst)
{
    int ret=1;
    vst[src]=true;

    for(ii there:adj[src])
    {
        if(!vst[there.first])
        {
            ret+=dfs(there.first, vst);
        }
    }

    forn(i, ret+1)
    {
        forn ggggggggggggg
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;

    int a,b,c;
    forn(i,n)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    V<bool> vst(n+1, false);

	return 0;
}

