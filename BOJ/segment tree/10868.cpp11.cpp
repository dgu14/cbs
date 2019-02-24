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

int n,m, arr[100005];
V<int> segt;

int init(int l, int r, int node)
{
    if(l>r) return INF;
    else if(l==r) return segt[node]=arr[l];

    int mid=(l+r)>>1;

    return segt[node]=min(init(l,mid,2*node), init(mid+1,r,2*node+1));
}

int query(int l, int r, int node, int ql, int qr)
{
    if(l>qr || ql>r) return INF;
    else if(ql<=l && qr>=r) return segt[node];

    int mid=(l+r)>>1;

    return min(query(l,mid,2*node,ql,qr), query(mid+1,r,2*node+1,ql,qr));
}

void input()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn(i,n) cin>>arr[i];
    segt=V<int> (4*n);

    init(0, n-1, 1);

    int a, b;
    forn(i,m)
    {
        cin>>a>>b;
        cout << query(0,n-1,1,a-1,b-1) << '\n';
    }
}

int main()
{

    input();


	return 0;
}
