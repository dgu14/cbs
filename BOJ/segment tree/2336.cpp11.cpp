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


int n, arr[500005][3];
ii a[500005];
V<int> segt;

void init()
{
    segt=V<int>(4*n, INF);
}

int update(int l, int r, int node, int idx, int val)
{
    if(l>r) return INF;
    if(l>idx || idx>r) return segt[node];
    if(l==r) return segt[node]=val;

    int mid=(l+r)>>1;
    return segt[node]=min(update(l,mid,2*node,idx,val), update(mid+1,r,2*node+1,idx,val));
}

int query(int l, int r, int node, int pl, int pr)
{
    if(l>=pl && r<=pr) return segt[node];
    if(l>pr || pl>r) return INF;

    int mid=(l+r)>>1;
    return min(query(l, mid, 2*node, pl, pr), query(mid+1, r, 2*node+1, pl, pr));
}

void solve()
{
    forn(i,n) a[arr[i][0]]={arr[i][1], arr[i][2]};

    init();
    int ret=0;
    forn(i,n)
    {
        int min_t=query(0,n-1,1,0,a[i].first-1);
        if(min_t>a[i].second) ret++;
        update(0,n-1,1,a[i].first,a[i].second);
    }

    cout << ret << endl;
}

void input()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    int tt;
    forn(i,3)
    {
        forn(j,n)
        {
            cin>>tt;
            tt--;
            arr[tt][i]=j;
        }
    }
}

int main()
{
    input();
    solve();

	return 0;
}

/**
10
2 5 3 8 10 7 1 6 9 4
1 2 3 4 5 6 7 8 9 10
3 8 7 10 5 4 1 2 6 9

5
1 2 3 4 5
2 1 3 4 5
1 2 3 4 5
*/
