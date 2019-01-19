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

int tc, n,d,c,p,q,r;
V<ii> adj[10050];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>tc;

    while(tc--)
    {
        forn(i,10050) adj[i].clear();

        cin>>n>>d>>c;
        c--;

        forn(i,d)
        {
            cin>>p>>q>>r;
            p--; q--;
            adj[q].push_back({p,r});
        }

        priority_queue<ii, V<ii>, greater<ii>> pq;
        int dist[10050];
        forn(i,10050) dist[i]=INF;
        pq.push({0,c});
        dist[c]=0;

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

        int ret=0, m_t=-1;
        forn(i,n)
        {
            if(dist[i]!=INF)
            {
                ret++;
                m_t=max(m_t, dist[i]);
            }
        }

        cout << ret << ' ' << m_t << '\n';
    }

	return 0;
}

