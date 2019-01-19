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

int n,m,a,b,c;
V<ii> edgs[1050];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,m)
    {
        cin>>a>>b>>c;
        a--;b--;
        edgs[a].push_back({b,c});
        edgs[b].push_back({a,c});
    }


    priority_queue<ii, V<ii>, greater<ii>> pq;
    int dist[1050];
    int parent[1050];
    forn(i,1050) dist[i]=INF;
    pq.push({0,0});

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(dist[here.second]<here.first) continue;

        forn(i,edgs[here.second].size())
        {
            int there=edgs[here.second][i].first;
            int cost=edgs[here.second][i].second;

            if(dist[there]>here.first+cost)
            {
                dist[there]=here.first+cost;
                parent[there]=here.second;
                pq.push({here.first+cost, there});
            }
        }
    }

    cout << n-1 << '\n';
    forn(i,n)
    {
        if(i==0) continue;
        cout << i+1 << " " << parent[i]+1 << '\n';
    }

	return 0;
}

