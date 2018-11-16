#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
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

int n,m, height[105], dp[505][105],a,b,c,q;
V<int> adj[105];


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn(i,n) cin>>height[i];
    forn(i,m)
    {
        cin>>a>>b;
        a--;b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    forn(i,505)
    {
        forn(j,105)
        {
            dp[i][j]=INF;
        }
    }

    forn(i,n)
    {
        forn(j,adj[i].size())
        {
            dp[1][i]=min(dp[1][i], height[adj[i][j]]);
        }
    }

    forn1(i,504)
    {
        if(i==1) continue;
        forn(j,n)
        {
            forn(k, adj[j].size())
            {
                dp[i][j]=min(dp[i][j], dp[i-1][adj[j][k]]);
            }
        }
    }


    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        a--;

        if(dp[b][a]==INF) cout << -1 << '\n';
        else cout << dp[b][a] << '\n';
    }

	return 0;
}

