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

int tc, n,m,t;
int s,g,h,a,b,c;
int cd[2050];
V<ii> adj[2050];

V<int> solve()
{
    priority_queue<ii, V<ii>, greater<ii>> pq;
    V<int> dist(2050);
    forn(i,2050) dist[i]=INF;
    pq.push({0,s});
    dist[s]=0;

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(dist[here.second]<here.first) continue;

        forn(i,adj[here.second].size())
        {
            int there=adj[here.second][i].first;
            int cost=adj[here.second][i].second;

            if(dist[there]>here.first+cost)
            {
                dist[there]=here.first+cost;
                pq.push({here.first+cost, there});
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>tc;

    while(tc--)
    {
        forn(i,2050) adj[i].clear();

        cin>>n>>m>>t;
        cin>>s>>g>>h;
        s--;g--;h--;

        forn(i,m)
        {
            cin>>a>>b>>c;
            a--; b--;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        forn(i,t)
        {
            cin>>a;
            a--;
            cd[i]=a;
        }

        int test[105], test2[105];

        V<int> dist=solve();

        forn(i,t)
        {
            test[i]=dist[cd[i]];
        }

        forn(i,adj[g].size())
        {
            if(adj[g][i].first==h) adj[g][i].second--;
        }

        forn(i,adj[h].size())
        {
            if(adj[h][i].first==g) adj[h][i].second--;
        }

        dist=solve();

        forn(i,t)
        {
            test2[i]=dist[cd[i]];
        }

        V<int> ret;
        forn(i,t)
        {
            if(test[i]!=test2[i])
            {
                ret.push_back(cd[i]+1);
            }
        }

        sort(ret.begin(), ret.end());
        forn(i,ret.size())
        {
            cout << ret[i] << " ";
        }
        cout << '\n';
    }

	return 0;
}

