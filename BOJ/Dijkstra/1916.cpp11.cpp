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

ll n,m,s,t;
V<V<lii>> adj;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m; adj.resize(n);
    ll a,b,c;
    forn(i,m) cin>>a>>b>>c, adj[a-1].push_back({c, b-1});
    cin>>s>>t; s--; t--;


    priority_queue<lii, V<ii>, greater<ii>> pq;
    V<bool> vst(n, false);
    V<ll> dist(n, LONG_INF);
    pq.push({0, s});

    while(pq.size())
    {
        lii h=pq.top(); pq.pop();
        if(dist[h.second] <= h.first) continue;
        dist[h.second]=h.first;
        vst[h.second]=true;

        for(lii th : adj[h.second])
        {
            if(!vst[th.second])
            {
                pq.push({dist[h.second]+th.first, th.second});
            }
        }
    }

    cout << dist[t] << endl;

	return 0;
}
