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

int n,k, adj[1050][1050], sz[1050], nc[1050];
V<V<int>> dp[1050][2]; V<int> chd[1050];
set<int> selected;

void mrg(int u, int v, int c, int nn)
{
    int su=nn, sv=sz[v];
    dp[u][0][c].resize(su+sv); dp[u][1][c].resize(su+sv);
    forn(i, su+sv) dp[u][0][c][i]=dp[u][1][c][i]=INF;

    forn(i,su)
    {
        forn(j,sv)
        {
            dp[u][0][c][i+j+1]=min(dp[u][0][c][i+j+1], dp[u][0][c-1][i]+dp[v][0][nc[v]][j]+adj[u][v]);
            dp[u][0][c][i+j]=min(dp[u][0][c][i+j], dp[u][0][c-1][i]+dp[v][1][nc[v]][j]);

            dp[u][1][c][i+j+1]=min(dp[u][1][c][i+j+1], dp[u][1][c-1][i]+dp[v][0][nc[v]][j]);
            dp[u][1][c][i+j]=min(dp[u][1][c][i+j], dp[u][1][c-1][i]+dp[v][1][nc[v]][j]+adj[u][v]);
        }
    }
}

void dfs(int src, V<bool>& vst)
{
    vst[src]=true; int c=0; int nn=0;
    dp[src][0].resize(nc[src]+1); dp[src][1].resize(nc[src]+1);

    dp[src][0][c].resize(1); dp[src][1][c].resize(1);
    dp[src][0][c][0]=0; dp[src][1][c][0]=0;

    c++; nn++;

    forn1(dst, n)
    {
        if(adj[src][dst]>0 && !vst[dst])
        {
            dfs(dst, vst);
            mrg(src, dst, c,nn);
            c++; nn+=sz[dst];
        }
    }
}

void dfs2(int src, V<bool>& vst)
{
    vst[src]=true; sz[src]++;

    forn1(dst,n)
    {
        if(adj[src][dst]>0 && !vst[dst]) dfs2(dst, vst), nc[src]++, sz[src]+=sz[dst], chd[src].push_back(dst);
    }
}

void print(int src, int not_select, int ck)
{
    if(!not_select) ck--, selected.insert(src);
    int mc=dp[src][not_select][nc[src]][ck];

    rforn(i, nc[src])
    {
        int chn=chd[src][i];
        forn(j, sz[chn]+1)
        {
            if(ck-j>=0 && ck-j<dp[src][not_select][i].size())
            {
                if(j!=0 && dp[src][not_select][i][ck-j]+dp[chn][0][nc[chn]][j-1]+(!not_select?adj[src][chn]:0)==mc)
                {
                    print(chn, 0,j), ck=ck-j, mc-=dp[chn][0][nc[chn]][j-1]+(!not_select?adj[src][chn]:0);
                    break;
                }

                if(j!=sz[chn] && dp[src][not_select][i][ck-j]+dp[chn][1][nc[chn]][j]+(not_select?adj[src][chn]:0)==mc)
                {
                    print(chn, 1,j), ck=ck-j, mc-=dp[chn][1][nc[chn]][j]+(not_select?adj[src][chn]:0);
                    break;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k; int a,b,c;

    forn(i,n-1) cin>>a>>b>>c, adj[a][b]=c, adj[b][a]=c;

    assert(n!=1);

    V<bool> vst(1050, false); dfs2(1, vst);
    fill(vst.begin(), vst.end(), false); dfs(1, vst);

    cout << min(dp[1][0][nc[1]][k-1], dp[1][1][nc[1]][k]) << endl;

    if(dp[1][0][nc[1]][k-1]>dp[1][1][nc[1]][k]) print(1, 1, k);
    else print(1, 0, k);

    while(selected.size()!=k)
    {
        forn1(i,n)
        {
            if(!binary_search(selected.begin(), selected.end(), i)) selected.insert(i);
        }
    }

    for(auto it=selected.begin();it!=selected.end();it++)
    {
        cout<<*it<< ' ';
    }
    cout <<endl;

	return 0;
}



