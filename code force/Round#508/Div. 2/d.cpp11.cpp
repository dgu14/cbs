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

ll n, a[500005];

int main()
{
    ll absSum=0;
    cin>>n;
    forn(i,n) cin>>a[i], absSum+=abs(a[i]);


    bool allSame=true;
    forn(i,n-1) if(a[i]*a[i+1]<0) allSame=false;


    if(allSame && n==1)
    {
        cout << a[0] << endl;
        return 0;
    }

    if(allSame && a[0]>0)
    {
        ll mv=(ll)1e9+5;
        forn(i,n) mv=min(mv, a[i]);

        absSum-=2*mv;
    }
    else if(allSame && a[0]<0)
    {
        ll mv=(ll)1e9+5; mv=-mv;
        forn(i,n) mv=max(mv, a[i]);

        absSum+=2*mv;
    }

    cout << absSum << endl;


	return 0;
}

