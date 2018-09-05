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
int const MAX_ND=500000;


int N, g;
int a[800][800], b[800][800], dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
int ps[MAX_ND], ori[MAX_ND];
class triple
{
public: ll x,y,z;
};

int parent[MAX_ND], sz[MAX_ND], m_u=1, ret;
set<int> changed;

void init()
{
    m_u=1;

    for(auto it=changed.begin();it!=changed.end();it++)
    {
        parent[*it]=*it;
        sz[*it]=ps[ori[*it]];
    }

    changed.clear();
}

int find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

void merge(int a, int b)
{
    int pa=find(a), pb=find(b);
    if(pa!=pb)
    {
        parent[pa]=pb;
        sz[pb]=sz[pa]+sz[pb];
        m_u=max(m_u, sz[pb]);

        changed.insert(pa);
        changed.insert(pb);
    }
}




void dfs(int sx, int sy, V<V<bool>>& vst)
{
    vst[sx][sy]=true;

    forn(i, 4)
    {
        int nx=sx+dx[i], ny=sy+dy[i];

        if(nx>=0&&nx<N && ny>=0 && ny<N && !vst[nx][ny] && a[nx][ny]==a[sx][sy] && b[nx][ny]==b[sx][sy])
        {
            ori[nx*N+ny]=ori[sx*N+sy];
            ps[ori[nx*N+ny]]++;
            dfs(nx, ny, vst);
        }
    }
}

class quad
{
public: ll x,y,u,v;
};
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    scanf("%d", &N);

    forn(i,N) forn(j,N) scanf("%d", &a[i][j]);
    forn(i,N) forn(j,N) scanf("%d", &b[i][j]);

    V<V<bool>> vst(N, V<bool> (N, false));

    forn(i,N)
    {
        forn(j, N)
        {
            if(!vst[i][j]) ps[i*N+j]=1, ori[i*N+j]=i*N+j, dfs(i,j,vst), ret=max(ret, ps[i*N+j]);
        }
    }

    V<quad> e;
    forn(i,N)
    {
        forn(j,N)
        {
            if(i!=N-1)
            {
                if(b[i][j]!=b[i+1][j])
                {
                    ll u=a[i][j]-a[i+1][j], v=b[i+1][j]-b[i][j];

                    if(v==0 || u*v<0) continue;
                    if(u<0) u=-u, v=-v;
                    else if(u==0) v=abs(v);
                    e.push_back({ori[i*N+j], ori[(i+1)*N+j], u, v});
                }
            }

            if(j!=N-1)
            {
                if(b[i][j]!=b[i][j+1])
                {
                    ll u=a[i][j]-a[i][j+1], v=b[i][j+1]-b[i][j];

                    if(v==0 || u*v<0) continue;
                    if(u<0) u=-u, v=-v;
                    else if(u==0) v=abs(v);
                    e.push_back({ori[i*N+j], ori[i*N+j+1], u, v});
                }
            }
        }
    }

    sort(e.begin(), e.end(), [](quad& a, quad& b)
         {
             return a.u * b.v < a.v* b.u;
         });


    forn(i, N)
    {
        forn(j,N)
        {
            changed.insert(ori[i*N+j]);
        }
    }

    forn(i, e.size())
    {
        if(i==0 || e[i].u*e[i-1].v != e[i].v*e[i-1].u) init();
        merge(e[i].x, e[i].y);

        ret=max(ret, m_u);
    }

    printf("%d\n", ret);
	return 0;
}
