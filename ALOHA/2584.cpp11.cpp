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

int n,k, adj[1050][1050], sz[1050], dp[1050][1050][2], tdp[1050][2];
V<int> sel[1005][1005];
V<int> selected;
void mrg(int u, int v)
{
    forn(i,sz[u]+sz[v]) tdp[i][0]=tdp[i][1]=INF;

    int pv, pj;
    forn(i,sz[u])
    {
        forn(j,sz[v])
        {
            forn(q, 2)
            {
                if(tdp[i+j+(q==0)][0] > dp[u][i][0]+dp[v][j][q])
                {
                    tdp[i+j+(q==0)][0]=dp[u][i][0]+dp[v][j][q]);
                    pv=v; pj=j;
                }
            }
        }
    }

    sel[u][i+j+(q==0)][0].push_back({v,j});

    forn(i,sz[u])
    {
        forn(j,sz[v])
        {
            forn(q,2)
            {
                if(tdp[i+j+(q==0)][1] > dp[u][i][1]+dp[v][j][q]+(q==1?adj[u][v]:0))
                {
                    tdp[i+j+(q==0)][1] = dp[u][i][1]+dp[v][j][q]+(q==1?adj[u][v]:0);
                    pv=v; pj=j;
                }
            }
        }
    }

    sel[u][i+j+(q==0)][1].push_back({v,j});

    forn(i,sz[u]+sz[v]) dp[u][i][0]=tdp[i][0], dp[u][i][1]=tdp[i][1];
}

void dfs(int src, V<bool>& vst)
{
    vst[src]=true; sz[src]++; dp[src][0][0]=0; dp[src][0][1]=0;

    forn1(dst, n)
    {
        if(adj[src][dst]>0 && !vst[dst])
        {
            dfs(dst, vst); mrg(src, dst); sz[src]+=sz[dst];
        }
    }
}

void print(int src, int max_val, V<bool>& vst)
{
    // 시작은 루트값이 선택됬나 안됬냐를 알수있다.
    //

    forn1(dst, n)
    {
        if(adj[src][dst]>0 && !vst[src])
        {

        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k; int a,b,c;
    forn(i,n-1) cin>>a>>b>>c, adj[a][b]=c, adj[b][a]=c;

    V<bool> vst(1050, false);
    dfs(1, vst);

    cout << min(dp[1][k-1][0], dp[1][k][1]) << endl;



	return 0;
}

/**
6 2
1 2 1
1 4 1
1 3 2
3 5 1
3 6 2


7 2
1 2 10
1 3 15
1 4 30
5 3 20
6 3 10
4 7 25
*/
