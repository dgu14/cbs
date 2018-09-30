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

ll a,b,c, n, x[1000005], dp[1000005], s[1000005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>a>>b>>c;
    forn1(i,n) cin>>x[i];
    forn1(i,n) s[i]=s[i-1]+x[i];

    ll j=0;
    forn1(i,n)
    {
        ll cv=dp[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;
        while(i>j+1)
        {
            ll nv=dp[j+1]+a*(s[i]-s[j+1])*(s[i]-s[j+1])+b*(s[i]-s[j+1])+c;
            if(nv>=cv) j++, cv=nv;
            else break;
        }

        dp[i]=cv;
    }

    cout << dp[n] << endl;

	return 0;
}
