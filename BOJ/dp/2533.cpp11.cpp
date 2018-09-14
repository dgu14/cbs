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

int n, c[1000005];
V<V<int>> adj;


int dfs(int src, V<bool>& vst)
{
    vst[src]=true;
    int cc=0;

    for(int there:adj[src])
    {
        if(!vst[there])
        {
            if(!dfs(there, vst)) cc=1;
        }
    }

    return c[src]=cc;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; int a,b; adj.resize(n+1);
    forn(i,n-1) { cin>>a>>b; adj[a].push_back(b); adj[b].push_back(a); }

    V<bool> vst(n+1, false);
    dfs(1, vst); int ret=0;
    forn1(i,n) ret+=c[i];

    cout << ret << endl;

	return 0;
}

