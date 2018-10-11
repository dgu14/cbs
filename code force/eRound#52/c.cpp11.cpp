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

ll n,k,h[300000], s[300000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>k;
    forn1(i,n) cin>>h[i];

    sort(h+1, h+n+1);
    forn1(i,n) s[i]=s[i-1]+h[i];

    ll ret=0;
    ll tt=0;
    for(ll i=h[1]+1;i<=h[n];i++)
    {
        ll p=lower_bound(h+1, h+n+1, i)-h;
        ll w=n-p+1;

        if(i==h[1]+1 || w*i+s[p-1]-tt>k) // h[1]은 무조건 커팅..
        {
            ll q=lower_bound(h+1, h+n+1, i-1)-h;
            tt=(n-q+1)*(i-1)+s[q-1];
            ret++;
        }
    }

    cout << ret << endl;

	return 0;
}
