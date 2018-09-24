#include<bits/stdc++.h>
using namespace std;

template <class T, class Q> class duo {public: T x; Q y; bool operator<(duo<T,Q> const& rhs){ return (x==rhs.x?y<rhs.y:x<rhs.x); }};
template <class T, class Q, class U> class triple {public: T x; Q y; U z; bool operator<(triple<T,Q,U> const& rhs){ return (x==rhs.x?(y==rhs.y?z<rhs.z:y<rhs.y):x<rhs.x);}};
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
        int n, m;
        cin>>n>>m;

        if(n==0 && m==0) break;

        int s,d;
        cin>>s>>d;

        int dp[505][505];
        V<ii> adj[505];

        forn(i,n) forn(j,n) dp[i][j]=INF;
        forn(i,n) dp[i][i]=0;

        int a,b,c;
        forn(i,m)
        {
            cin>>a>>b>>c;
            dp[a][b]=c;
            adj[a].push_back({b, c});
        }

        forn(i,n)
        {
            forn(j,n)
            {
                forn(k,n)
                {
                    dp[j][k]=min(dp[j][k], dp[j][i]+dp[i][k]);
                }
            }
        }

        priority_queue<ii, V<ii>, greater<ii>> q;
        q.push({0, s});

        V<bool> vst(505, false);
        V<int> dist(505, INF);

        while(q.size())
        {
            ii here=q.top(); q.pop();
            if(dist[here.second]<=here.first) continue;

            dist[here.second]=here.first;
            vst[here.second]=true;

            if(here.second==d) break;

            for(ii there:adj[here.second])
            {
                if(!vst[there.first] && dp[s][here.second]+dp[there.first][d]+there.second!=dp[s][d])
                {
                    q.push({here.first+there.second, there.first});
                }
            }
        }

        if(dist[d]==INF) cout << -1 << '\n';
        else cout << dist[d] << '\n';

    }

	return 0;
}

