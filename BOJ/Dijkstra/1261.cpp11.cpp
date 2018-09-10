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

int m,n, arr[105][105];
V<V<ii>> adj;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>m>>n; adj.resize(m*n);
    forn(i,n)
    {
        string tmp;
        cin>>tmp;

        forn(j,m) arr[i][j]=tmp[j]-'0';
    }

    forn(i,n)
    {
        forn(j,m)
        {
            if(i!=n-1)
            {
                adj[i*m+j].push_back({arr[i+1][j], (i+1)*m+j});
                adj[(i+1)*m+j].push_back({arr[i][j], i*m+j});
            }
            if(j!=m-1)
            {
                adj[i*m+j].push_back({arr[i][j+1], i*m+j+1});
                adj[i*m+j+1].push_back({arr[i][j], i*m+j});
            }
        }
    }


    int s=0, t=m*n-1;

    V<int> dist(m*n, INF);
    priority_queue<ii, V<ii>, greater<ii> > pq;
    pq.push({0,s});

    while(pq.size())
    {
        ii h=pq.top(); pq.pop();

        if(dist[h.second]<=h.first) continue;

        dist[h.second]=h.first;

        for(ii th:adj[h.second])
        {
            if(dist[h.second]+th.first<dist[th.second]) pq.push({dist[h.second]+th.first, th.second});
        }
    }

    cout << dist[t] << endl;

	return 0;
}

