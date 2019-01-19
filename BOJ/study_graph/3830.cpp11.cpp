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

ll n,m;
V<ll> adj[100050];

/// 링크드 리스트 형식으로 짜면됨
/// 대표값, 대표값까지의 거리를 저장하는 배열
/// 그리고 합병할때 해당 대표값을 가지는 수의 배열 -> adj로 처리

ll parent[100050], dist[100050], rnk[100050];

void init()
{
    forn(i,100050) adj[i].clear(), parent[i]=i, dist[i]=0, rnk[i]=1;
    forn(i,100050) adj[i].push_back(i);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        cin>>n>>m; if(n==0 && m==0) break;
        char ch; int a,b,c;

        init();
        while(m--)
        {
            cin>>ch;
            if(ch=='!')
            {
                cin>>a>>b>>c;
                a--;b--;

                if(parent[a]!=parent[b])
                {
                    c=c-dist[a]+dist[b];
                    a=parent[a]; b=parent[b];
                    if(rnk[a]>rnk[b]) swap(a,b),c=-c;

                    rnk[b]+=rnk[a];
                    rnk[a]=0;
                    forn(j,adj[a].size())
                    {
                        parent[adj[a][j]]=b;
                        adj[b].push_back(adj[a][j]);
                        dist[adj[a][j]]+=c;
                    }

                    adj[a].clear();
                }
            }
            else
            {
                cin>>a>>b;
                a--;b--;

                if(parent[a]!=parent[b])
                {
                    cout << "UNKNOWN" << '\n';
                }
                else
                {
                    cout << dist[a]-dist[b] << '\n';
                }
            }
        }
    }

	return 0;
}
