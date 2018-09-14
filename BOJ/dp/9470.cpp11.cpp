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

int dfs(int src, V<V<int>>& adj)
{
    int m1=0, m2=0, m;
    for(int obj:adj[src])
    {
        m=dfs(obj, adj);
        if(m>m1) m2=m1, m1=m;
        else if(m>m2) m2=m;
    }

    if(m1!=0)
    {
        if(m1==m2) return m1+1;
        else return m1;
    }

    return 1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin>>tt;
    while(tt--)
    {
        V<V<int>> adj(1005);
        int tn, m,p,a,b;
        cin>>tn>>m>>p;

        forn(i,p) { cin>>a>>b; adj[b].push_back(a); }

        cout << tn << " " << dfs(m, adj) << '\n';
    }

	return 0;
}

