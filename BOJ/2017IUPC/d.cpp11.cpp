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

int n,m,tt;
V<int> adj[100005];
V<int> adj2[100005];
V<bool> onetoevery;
V<bool> ntoevery;

void dfs(int src, V<bool>& vst, int flag)
{
    vst[src]=true;

    if(flag)
    {
        forn(i, adj2[src].size())
        {
            if(!vst[adj2[src][i]]) dfs(adj2[src][i], vst,1);
        }
    }
    else
    {
        forn(i, adj[src].size())
        {
            if(!vst[adj[src][i]]) dfs(adj[src][i], vst,0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    int a,b;

    onetoevery.resize(100005);
    ntoevery.resize(100005);

    forn(i,m)
    {
        cin>>a>>b;a--;b--;
        adj[b].push_back(a);
        adj2[a].push_back(b);
    }

    dfs(0, onetoevery, 1);
    dfs(n-1, ntoevery, 0);

    cin>>tt;
    forn(i,tt)
    {
        cin>>a; a--;

        if(onetoevery[a] && ntoevery[a])
        {
            cout << "Defend the CTP" << '\n';
        }
        else cout << "Destroyed the CTP" << '\n';
    }


	return 0;
}

