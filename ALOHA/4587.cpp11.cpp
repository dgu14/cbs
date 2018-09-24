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

int main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        ll a,b; V<ll> f;
        cin>>a>>b;

        if(a==0&&b==0) break;

        ll c=2;

        ll p,q;

        while(c<1000000)
        {
            p=a*c-b;
            q=b*c;

            if(p<0)
            {
                c++;
                continue;
            }

            ll g=gcd(p,q);
            p=p/g;
            q=q/g;

            if(q>=1000000);
            else
            {
                f.push_back(c);
                a=p; b=q;
            }

            c++;
        }

        while(a--)
        {
            f.push_back(b);
        }

        forn(i, f.size())
        {
            cout << f[i] << ' ';
        }
        cout << '\n';
    }

	return 0;
}

