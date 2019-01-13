// 2014004193_choibeomseok_508
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int n,m,a,b,c,p,q,dist[5005];
vector<ii> adj[5005];

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>p>>q;
        p--;
        for(int j=0;j<q;j++)
        {
            cin>>a>>b;
            a--;

            adj[p].push_back({a,b});
        }
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, 0});
    for(int i=0;i<5005;i++) dist[i]=2000000000;

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(here.first>dist[here.second]) continue;
        dist[here.second]=here.first;

        for(int i=0;i<adj[here.second].size();i++)
        {
            int there=adj[here.second][i].first;
            int cost=adj[here.second][i].second;

            if(dist[there]>dist[here.second]+cost)
            {
                dist[there]=dist[here.second]+cost;
                pq.push({dist[there], there});
            }
        }
    }

    int max_t=-1;
    for(int i=0;i<n;i++)
    {
        max_t=max(max_t, dist[i]);
    }

    cout << max_t << endl;

    return 0;
}
