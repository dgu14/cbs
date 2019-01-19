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

int n,a,b, depth[300050], parent[300050], vst[300050];
int lng[300050][2];
V<int> adj[300050];

void dfs(int a)
{
    vst[a]=1;
    forn(i, adj[a].size())
    {
        if(!vst[adj[a][i]])
        {
            depth[adj[a][i]]=depth[a]+1;
            parent[adj[a][i]]=a;
            dfs(adj[a][i]);
        }
    }
}

int dfs2(int a, int ss)
{
    vst[a]=1;

    int m1=-1, m2=-1;
    forn(i,adj[a].size())
    {
        if(!vst[adj[a][i]])
        {
            m2=max(m2, dfs2(adj[a][i], ss));
            if(m2>m1) swap(m1, m2);

            lng[a][ss]=max(lng[a][ss], lng[adj[a][i]][ss]);
        }
    }

    lng[a][ss]=max(lng[a][ss], (m1==-1?0:m1+1)+(m2==-1?0:m2+1));

    return m1+1;
}

V<int> diam(int s, int d)
{
    memset(depth,255,sizeof(depth));
    memset(vst,0,sizeof(vst));
    memset(parent,255,sizeof(parent));

    if(d!=-1) vst[d]=1;

    depth[s]=0; dfs(s);
    int md=max_element(depth, depth+n)-depth;

    memset(parent, 255, sizeof(parent));
    memset(depth, 255, sizeof(depth));
    memset(vst, 0, sizeof(vst));

    if(d!=-1) vst[d]=1;

    depth[md]=0; dfs(md);
    int ml=max_element(depth, depth+n)-depth;
    int ff=ml;

    V<int> ret;
    while(ff!=-1)
    {
        ret.push_back(ff);
        ff=parent[ff];
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    forn(i,n-1)
    {
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    V<int> ds=diam(0, -1);

    memset(vst, 0, sizeof(vst));
    dfs2(ds[0], 0);
    memset(vst, 0, sizeof(vst));
    dfs2(ds[ds.size()-1], 1);

    int m_t=INF, ri=-1;
    forn(i,ds.size()-1)
    {
        int p=lng[ds[i+1]][0], q=lng[ds[i]][1];
        int prmt=m_t;

        //cout << ds[i] << "," << ds[i+1] << " Àý´Ü" << endl;
        //cout << p << "," << q << endl;
        m_t=min(m_t, max({p, q, (p+1)/2+(q+1)/2+1})); if(prmt!=m_t) ri=i;
    }

    V<int> upper=diam(ds[ds.size()-1], ds[ri]);
    V<int> lower=diam(ds[0], ds[ri+1]);

    cout << m_t << endl;
    cout << ds[ri]+1 << " " << ds[ri+1]+1 << endl;
    cout << upper[upper.size()/2]+1 << " " << lower[lower.size()/2]+1 << endl;

	return 0;
}
