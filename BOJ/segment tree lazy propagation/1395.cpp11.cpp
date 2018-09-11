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


int n,m, st[400000], lz[400000], a,b,c;


int query(int nd, int pl, int pr, int l, int r)
{
    if(l>pr || r<pl) return 0;
    if(l>=pl && r<=pr) return st[nd];

    int mid=(l+r)>>1;

    int ml=max(pl, l), mr=min(pr, r);
    return query(2*nd, pl, pr, l, mid)+query(2*nd+1, pl, pr ,mid+1, r)+lz[nd]*(mr-ml+1);
}

int update(int nd, int pl, int pr, int l, int r)
{
    if(l>pr || r<pl) return st[nd];
    if(l>=pl && r<=pr)
    {
        int k=query(1, l, r, 0, n-1);
        lz[nd]+=(r-l+1)-2*k;
        return st[nd]+=(r-l+1)-2*k;
    }

    int mid=(l+r)>>1;
    return st[nd]=update(2*nd, pl, pr, l,mid) +update(2*nd+1,pl, pr, mid+1, r) + lz[nd];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,m)
    {
        cin>>a>>b>>c;
        b--; c--;
        if(a==0)
        {
            if(b>c) swap(b,c);

            update(1,b,c,0,n-1);
        }
        else if(a==1)
        {
            if(b>c) swap(b,c);

            cout << query(1, b,c,0,n-1) <<'\n';
        }
    }

	return 0;
}

