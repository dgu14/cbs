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

int n,m, mw[1005];
int x[10005], y[10005], z[10005], pos[10005];

int parent[1005];

void init()
{
    forn(i,1005)
    {
        parent[i]=i;
    }
}

int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}

bool merge(int a, int b)
{
    int pa=find(a), pb=find(b);

    if(pa!=pb)
    {
        parent[pa]=pb;
        return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,n)
    {
        char ch;
        cin>>ch;

        if(ch=='M') mw[i]=0;
        else mw[i]=1;
    }

    forn(i,m)
    {
        cin>>x[i]>>y[i]>>z[i];
    }

    forn(i,m) pos[i]=i;


    sort(pos, pos+m, [&z](int a, int b)
         {
            if(z[a]<z[b]) return true;
            else return false;
         });

    init();
    int ret=0;
    forn(i,m)
    {
        int p=pos[i];
        if(mw[x[p]]==mw[y[p]]) continue;

        if(merge(x[p], y[p]))
        {
            ret+=z[p];
        }
    }

    int ff=-1;

    forn1(i,n)
    {
        if(ff==-1) ff=find(i);
        else
        {
            if(ff!=find(i))
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ret << endl;

	return 0;
}
