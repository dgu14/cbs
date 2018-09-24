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


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        int n,m;
        cin>>n>>m;

        if(n==0&&m==0) break;

        V<ii> adj[505], adj2[505];

        int s,d,a,b,c;
        cin>>s>>d;

        forn(i,m)
        {
            cin>>a>>b>>c;
            adj[a].push_back({c,b});
            adj2[b].push_back({c,a});
        }

        V<int> dist(505, INF);
        priority_queue<ii, V<ii>, greater<ii>> pq;

        pq.push({0, s});
        dist[s]=0;

        while(pq.size())
        {
            ii here=pq.top(); pq.pop();

            if(dist[here.second]<here.first) continue;
            dist[here.second]=here.first;

            for(ii there: adj[here.second])
            {
                if(dist[there.second]>here.first+there.first)
                {
                    pq.push({here.first+there.first, there.second});
                }
            }
        }

        V<bool> vst(505,false);
        queue<int> q;
        q.push(d);

        V<V<bool>> test(505, V<bool> (505, true));

        while(q.size())
        {
            int here=q.front(); q.pop();
            vst[here]=true;

            for(ii there:adj2[here])
            {
                if(dist[there.second]+there.first==dist[here])
                {
                    q.push(there.second); test[there.second][here]=false;
                }
            }
        }

        fill(dist.begin(), dist.end(), INF);

        pq.push({0, s});
        dist[s]=0;

        while(pq.size())
        {
            ii here=pq.top(); pq.pop();

            if(dist[here.second]<here.first) continue;
            dist[here.second]=here.first;

            for(ii there: adj[here.second])
            {
                if(test[here.second][there.second] && dist[there.second]>here.first+there.first)
                {
                    pq.push({here.first+there.first, there.second});
                }
            }
        }

        if(dist[d]==INF) cout << -1 << '\n';
        else cout << dist[d] << '\n';
    }
	return 0;
}

