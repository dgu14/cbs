#include<bits/stdc++.h>
using namespace std;

template <class T, class Q> class duo {public: T x; Q y; bool operator<(duo<T,Q> const& rhs){ return (x==rhs.x?y<rhs.y:x<rhs.x); }};
template <class T, class Q, class U> class triple {public: T x; Q y; U z; bool operator<(triple<T,Q,U> const& rhs){ return (x==rhs.x?(y==rhs.y?z<rhs.z:y<rhs.y):x<rhs.x);}};
template <class T> using V=vector<T>;

using ll=long long;
using dbl=double;
using ii=duo<int,int>;
using lii=duo<ll,ll>;
using iii=triple<int,int,int>;
using liii=triple<ll,ll,ll>;
using dii=duo<dbl,dbl>;
using diii=triple<dbl,dbl,dbl>;

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

int e,s,m;

const int MAX=30*30*30;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>e>>s>>m;

    int  ret=-1;
    forn(i, MAX)
    {
        if(i%15+1==e && i%28+1==s && i%19+1==m)
        {
            ret=i;
            break;
        }
    }

    cout << ret+1 << endl;

	return 0;
}

