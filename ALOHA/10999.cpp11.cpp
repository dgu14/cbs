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

ll n,m,k;
V<ll> arr, st, lz;

ll init(int nd, int l, int r)
{
    if(l==r) return st[nd]=arr[l];
    int mid=(l+r)>>1;

    return st[nd]=init(2*nd, l, mid) + init(2*nd+1, mid+1, r);
}

void precalc()
{
    st=V<ll> (4*n,0);
    lz=V<ll> (4*n,0);
    init(1, 0, n-1);
}

ll query(int nd, int pl, int pr ,int l, int r)
{
    if(l>pr || r<pl) return 0;
    if(l>=pl && r<=pr)
    {
        return st[nd];
    }

    int mid=(l+r)>>1, ml=max(pl, l), mr=min(pr, r);
    return query(2*nd, pl, pr, l, mid) + query(2*nd+1, pl, pr, mid+1, r) + lz[nd]*(mr-ml+1);
}

ll update(int nd, int pl, int pr, int l, int r, ll val)
{
    if(l>pr || r<pl) return st[nd];
    if(l>=pl && r<=pr)
    {
        lz[nd]+=val, st[nd]+=val*(r-l+1);
        return st[nd];
    }

    int mid=(l+r)>>1;
    st[nd] = update(2*nd, pl, pr, l, mid, val)+update(2*nd+1, pl, pr, mid+1, r, val)+lz[nd]*(r-l+1);
    return st[nd];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k; arr.resize(n);

    ll a,b,c,d;
    forn(i,n) cin>>arr[i];

    precalc();
    forn(i,m+k)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c>>d;
            b--; c--;
            if(b>c) swap(b,c);
            update(1, b, c, 0, n-1, d);
        }
        else if(a==2)
        {
            cin>>b>>c;
            b--; c--;
            if(b>c) swap(b,c);
            cout << query(1, b,c, 0, n-1) << '\n';
        }
    }

	return 0;
}

