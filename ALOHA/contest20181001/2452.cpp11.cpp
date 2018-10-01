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

int m,n, mp[105][105], cnt=0, g[105][105], fd[10005];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
set<int> adj[10005];
V<int> adj2[10005];
void dfs(int i, int j)
{
    g[i][j]=cnt;

    forn(k,4)
    {
        if(i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n && g[i+dx[k]][j+dy[k]]==0 && mp[i][j]==mp[i+dx[k]][j+dy[k]])
        {
            dfs(i+dx[k], j+dy[k]);
        }
    }
}

int d;

int q[10005], s,e;

void initQ()
{
    s=0, e=0;
}

void pushQ(int val)
{
    q[e]=val;
    e=(e+1)%10005;
}

int frontQ()
{
    return q[s];
}

void popQ()
{
    s=(s+1)%10005;
}

int sizeQ()
{
    if(e>=s) return e-s;
    else return 10005-s+e;
}

int vstt[10005];
void bfs(int src)
{
    if(fd[src]>=d) return;
    initQ();
    pushQ(src);
    vstt[src]=src;

    int r=0;
    while(sizeQ())
    {
        int qSize=sizeQ();
        r++;

        while(qSize--)
        {
            int h=frontQ(); popQ(); fd[h]=max(fd[h], r);
            forn(i, adj2[h].size())
            {
                int q=adj2[h][i];
                if(vstt[q]!=src) pushQ(q), vstt[q]=src;
            }
        }
    }

    d=min(d, r);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>m>>n;
    forn(i,m)
    {
        forn(j,n)
        {
            cin>>mp[i][j];
        }
    }


    forn(i,m)
    {
        forn(j,n)
        {
            if(g[i][j]==0)
            {
                ++cnt;
                dfs(i,j);
            }
        }
    }

    forn(i,m)
    {
        forn(j,n)
        {
            if(i+1<m && g[i][j]!=g[i+1][j])
            {
                adj[g[i][j]].insert(g[i+1][j]);
                adj[g[i+1][j]].insert(g[i][j]);
            }

            if(j+1<n && g[i][j]!=g[i][j+1])
            {
                adj[g[i][j]].insert(g[i][j+1]);
                adj[g[i][j+1]].insert(g[i][j]);
            }
        }
    }


    forn1(i,cnt)
    {
        for(int th:adj[i])
        {
            adj2[i].push_back(th);
        }
    }

    d=INF;

    set<int> candi;
    bool check[10005]={false,};

    forn(i,m)
    {
        forn(j,n)
        {
            if(i>=2*m/5 && i<=4*m/5 && j>=2*n/5 && j<=4*n/5)
            {
                candi.insert(g[i][j]);
            }
        }
    }

    for(auto it=candi.begin();it!=candi.end();it++)
    {
        bfs(*it); check[*it]=1;
    }

    forn1(i, cnt)
    {
        if(check[i] == 0)
        {
            bfs(i);
        }
    }

    cout << d-1 << endl;


	return 0;
}

