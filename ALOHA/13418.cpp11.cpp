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


int n,m,parent[1005];

void init()
{
    forn(i,1005) parent[i]=i;
}

int fnd(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=fnd(parent[a]);
}

int mrg(int a,int b)
{
    int pa=fnd(a), pb=fnd(b);
    if(pa!=pb)
    {
        parent[pa]=pb;
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    V<ii> asc,dsc;
    int a,b,c;

    forn(i,m+1)
    {
        cin>>a>>b>>c;

        if(c==0)
        {
            asc.push_back({a,b});
        }
        else dsc.push_back({a,b});
    }

    // min
    int mc=0,nc=0;

    init ();
    forn(i,dsc.size())
    {
        mrg(dsc[i].first, dsc[i].second);
    }

    forn(i,asc.size())
    {
        nc+=mrg(asc[i].first, asc[i].second);
    }

    init();

    forn(i,asc.size())
    {
        mc+=mrg(asc[i].first, asc[i].second);
    }

    forn(i,dsc.size())
    {
        mrg(dsc[i].first, dsc[i].second);
    }

    cout << (mc-nc)*(mc+nc) << endl;
	return 0;
}
