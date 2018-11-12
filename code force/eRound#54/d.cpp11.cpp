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

int n,m,k,x,y,w;
V<ii> adj[300005];
int ddalin[300005], bad[300005];
V<int> parent[300005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k;

    k=m-k;
    forn(i,m)
    {
        cin>>x>>y>>w;
        x--;y--;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    priority_queue<ii, V<ii>, greater<ii>> pq;
    V<bool> vst(n, false);
    V<int> dist(n, INF);
    pq.push({0, 0});

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(dist[here.second]<here.first) continue;
        dist[here.second]=here.first;
        vst[here.second]=true;

        for(int i=0;i<adj[here.second].size();i++)
        {
            int there=adj[here.second][i].first;
            int cost=adj[here.second][i].second;

            if(!vst[there] && dist[there]>dist[here.second]+cost)
            {
                pq.push({dist[here.second]+cost, there});
            }
        }
    }

    // bfs 트리 구성

    // 트리 노드가 아닌거는 k--
    int s=0;
    forn(i,n)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int there=adj[i][j].first;
            int cost=adj[i][j].second;

            // 최단거리인 경우
            if(dist[i]==dist[there]+cost)
            {
                ddalin[there]++; // 딸린거 하나 플러스.
                parent[i].push_back(there);
            }
            else if(dist[there]==dist[i]+cost);
            else s++;
        }
    }

    k-=s/2;

    // 지우는 거는 어케 하냐
    // 딸린거 없는것부터 지우는데, 그 중에서도 parent갯수가 많은거부터 지운다.

    forn(i,n)
    {
        pq.push({ddalin[i], i});
    }

    while(pq.size() && k)
    {
        ii now=pq.top(); pq.pop();

        if(parent[now.second].size()>k)
        {
            k=0;
        }
        else
        {
            bad[now.second]=true;
            k-=parent[now.second].size();
        }
    }

    V<int> goods;
    forn(i,n)
    {
        if(!bad[i]) goods.push_back(i);
    }

    cout << goods.size() << '\n';
    for(int i=0;i<goods.size();i++)
    {
        cout << goods[i]+1 << ' ';
    }
    cout << '\n';

	return 0;
}

