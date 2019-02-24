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

ll n, a[500005], b[1000001], c[500005], pwt[500005];

void update(ll idx, ll val)
{
    while(idx<=500000)
    {
        pwt[idx]+=val;
        idx+=idx & -idx;
    }
}

ll query(ll idx)
{
    ll ret=0;
    while(idx)
    {
        ret+=pwt[idx];
        idx-=idx & -idx;
    }

    return ret;
}

void solve()
{
    forn1(i,n) update(i, 1);
    ll ret=0;

    forn1(i,n)
    {
        ret+=query(c[i]-1);
        update(c[i],-1);
    }

    cout << ret << endl;
}

void input()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; int tt;
    forn1(i,n) cin>>a[i]; forn1(i,n) cin>>tt, b[tt]=i;
    forn1(i,n)
    {
        c[i]=b[a[i]];
    }
}

int main()
{
    input();
    solve();

	return 0;
}

/*
5
132 392 351 311 231
132 392 311 231 351
*/
