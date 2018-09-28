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

ll n,k, arr[300000];


ll bit[100000];

void init()
{
    memset(bit, 0, sizeof(bit));
}

ll sum(int idx)
{
    int po=idx;
    ll ret=0;
    while(po)
    {
        ret+=bit[po];
        po-=po&-po;
    }

    return ret;
}

void update(int idx, ll val)
{
    int po=idx;

    while(po< 100000)
    {
        bit[po]+=val;
        po+=po&-po;
    }
}

int solve()
{
    int lo=0, hi=65536, mid, ret=-1;

    while(lo<=hi)
    {
        mid=(lo+hi)>>1;

        if(sum(mid)>=(k+1)/2)
        {
            ret=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;
    forn1(i,n) cin>>arr[i];


    ll ret=0;
    forn1(i,n)
    {
        update(arr[i]+1, 1);
        if(i-k>=1)
        {
            update(arr[i-k]+1, -1);
        }

        if(i>=k)
        {
            ret+=solve()-1;
        }
    }

    cout << ret << endl;

	return 0;
}

