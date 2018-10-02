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

int n, x[50005], y[50005];

V<int> xs, ys;
int xsz, ysz;
int A[50005], B[50005];
V<int> adj[50005];
bool vst[50005];

bool dfs(int src)
{
    if(vst[src]) return 0;
    vst[src]=1;

    for(int i=0;i<adj[src].size();i++)
    {
        int th=adj[src][i];
        if(B[th]==-1 || dfs(B[th]))
        {
            A[src]=th;
            B[th]=src;
            return 1;
        }
    }

    return 0;
}

int match()
{
    forn(i,ysz) B[i]=-1;
    int ret=0;
    forn(i,xsz)
    {
        memset(vst, 0, sizeof(vst));
        if(dfs(i))ret++;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    forn(i,n)
    {
        cin>>x[i]>>y[i];
        xs.push_back(x[i]); ys.push_back(y[i]);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    xsz=xs.size(); ysz=ys.size();

    forn(i,n)
    {
        x[i]=lower_bound(xs.begin(), xs.end(), x[i])-xs.begin();
        y[i]=lower_bound(ys.begin(), ys.end(), y[i])-ys.begin();
    }

    forn(i,n)
    {
        adj[x[i]].push_back(y[i]);
    }

    cout << (match()==3) << endl;

    return 0;
}

