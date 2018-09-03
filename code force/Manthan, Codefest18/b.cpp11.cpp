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

ll n,s, a[300000];

int main()
{
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n>>s;
        forn(i,n) cin>>a[i];

        ll ret=0;
        sort(a, a+n);

        if(a[n/2]>s)
        for(int i=0;i<=n/2;i++)
        {
            if(a[i]>s)
            {
                ret+=a[i]-s;
            }
        }
        else
        for(int i=n/2;i<n;i++)
        {
            if(a[i]<s)
            {
                ret+=s-a[i];
            }
        }


        cout << ret << endl;

    #endif

	return 0;
}

