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

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    if(n==1)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    // min
    ll l;
    ll mr=m;

    for(l=0;;l++)
    {
        if(2*m-l*(l-1) <= 0) break;
    }

    ll ret1=(n+1)/2-mr;
    if(ret1<=0) ret1=0;
    else
    {
        ret1=ret1*2;
        if(n%2==1) ret1--;
    }

    cout << ret1 << ' ' << n-l << endl;
	return 0;
}

