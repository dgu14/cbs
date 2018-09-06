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


int N, p[300003][25], ori[300003], depth[300003];

class triple
{
public:
    char ch;
    int v,w;
};

V<triple> q;


void dfs(int src, V<bool>& vst, V<V<int>>& adj)
{
    if(src==0) depth[0]=0;
    vst[src]=true;

    for(int there:adj[src])
    {
        if(!vst[there]) depth[there]=depth[src]+1, dfs(there, vst, adj);
    }
}

void precalc()
{
    forn(i,N)
    {
        forn(j,19)
        {
            if(p[i][j]==-1) p[i][j+1]=-1;
            else p[i][j+1]=p[p[i][j]][j];
        }
    }
}

int lca(int a, int b)
{
    if(depth[a]<depth[b]) swap(a,b);


    rforn(i, 20)
    {
        if(p[a][i]!=-1 && depth[p[a][i]] >= depth[b]) a=p[a][i];
    }

    if(a==b) return a;

    rforn(i, 20)
    {
        if(p[a][i]!=-1 && p[b][i]!=-1 && p[a][i]!=p[b][i]) a=p[a][i], b=p[b][i];
    }

    return p[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>N;
    q.resize(N+1);
    forn1(i,N)
    {
        cin>>q[i].ch>>q[i].v;
        if(q[i].ch=='c') cin>>q[i].w;
    }


    V<int> ans;
    V<V<int>> adj(N+1);
    forn(i, N+1) p[i][0]=-1;
    forn1(i,N) ori[i]=i;
    // tree 를 구성
    // root는 0

    forn1(i,N)
    {
        if(q[i].ch=='a')
        {
            // i를 v 밑에다가 붙여야함
            int v=ori[q[i].v];
            adj[v].push_back(i);
            adj[i].push_back(v);
            p[i][0]=v;
        }
        else if(q[i].ch=='b')
        {
            // i는 parent[v] 이다 출력은 v를 출력해야함.
            int v=ori[q[i].v];
            ori[i]=p[v][0];
            ans.push_back(v);
        }
        else
        {
            int v=ori[q[i].v];
            // i는 v다
            ori[i]=v;
        }
    }

    V<bool> vst(N+1, false);
    dfs(0, vst, adj); // depth search
    precalc(); // lca precalc

    int c=0;
    forn1(i,N)
    {
        if(q[i].ch=='b')
        {
            cout << ans[c++] << '\n';
        }
        else if(q[i].ch=='c')
        {
            cout << depth[lca(ori[q[i].v], ori[q[i].w])] << '\n';
        }
    }

	return 0;
}
