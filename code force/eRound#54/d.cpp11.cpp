#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,int>;
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
int parent[300005];
map<ii, int> mp;

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

        mp[{x,y}]=mp[{y,x}]=i;
    }

    priority_queue<lii, V<lii>, greater<lii>> pq;
    V<bool> vst(n, false);
    V<ll> dist(n, LONG_INF);
    pq.push({0L, 0});

    while(pq.size())
    {
        lii here=pq.top(); pq.pop();
        if(dist[here.second]<here.first) continue;
        dist[here.second]=here.first;
        vst[here.second]=true;

        for(int i=0;i<adj[here.second].size();i++)
        {
            ll there=adj[here.second][i].first;
            ll cost=adj[here.second][i].second;

            if(!vst[there] && dist[there]>dist[here.second]+cost)
            {
                pq.push({dist[here.second]+cost, there});
            }
        }
    }

    int s=0, d=0;
    fill(parent, parent+300005, -1);
    forn(i,n)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            ll there=adj[i][j].first;
            ll cost=adj[i][j].second;

            if(dist[i]==dist[there]+cost)
            {
                if(parent[i]==-1)
                {
                    parent[i]=there;
                    ddalin[there]++;
                }
                else d++;
            }
            else if(dist[there]==dist[i]+cost);
            else s++;
        }
    }

    k-=s/2;
    k-=d;
    set<int> notIncluded;
    if(k<0)
    {
        forn(i,n)
        {
            forn(j,adj[i].size())
            {
                ll there=adj[i][j].first;
                ll cost=adj[i][j].second;

                if(there!=parent[i] && parent[there]!=i)
                {
                    notIncluded.insert(mp[{i, there}]);

                    if(notIncluded.size()+k==0) break;
                }
            }

            if(notIncluded.size()+k==0) break;
        }
    }

    queue<ll> qq;

    forn(i,n)
    {
        if(ddalin[i]==0) qq.push(i);
    }

    while(k>0 && qq.size())
    {
        ll tt=qq.front(); qq.pop();

        ddalin[parent[tt]]--; k--;
        bad[tt]=true;

        if(ddalin[parent[tt]]==0)
        {
            qq.push(parent[tt]);
        }
    }

    V<ll> goods;
    forn(i,n)
    {
        if(!bad[i] && i!=0)
        {
            goods.push_back(mp[{i, parent[i]}]);
        }
    }

    for(auto it=notIncluded.begin();it!=notIncluded.end();it++)
    {
        goods.push_back(*it);
    }

    cout << goods.size() << endl;
    forn(i, goods.size()) cout << goods[i]+1 << ' ';
    cout <<endl;

	return 0;
}
