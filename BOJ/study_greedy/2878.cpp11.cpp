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


using ull=unsigned long long;
ull m,n, arr[200000], sum[200000], ret, tot;
ull MOD=(1<<64)-1;

ull getUpper(ull k)
{
    ull po=upper_bound(arr, arr+n+1, k)-arr;

    return sum[n]-sum[po-1]-(n-po+1)*k;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>m>>n;

    forn1(i,n) cin>>arr[i];


    sort(arr,arr+n+1);
    forn1(i,n) sum[i]=sum[i-1]+arr[i];
    tot=sum[n];

    ull hgt,lo,hi,mid;

    lo=0, hi=2000000000;

    while(lo<=hi)
    {

        mid=(lo+hi)>>1;
        if(getUpper(mid)<=m)
        {
            hgt=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    forn1(i,n)
    {
        if(arr[i]>hgt)
        {
            m-=arr[i]-hgt;
            arr[i]=hgt;
        }
    }

    sort(arr, arr+n+1);

    rforn1(i,n)
    {
        if(m) arr[i]--, m--;
    }


    forn1(i,n)
    {
        ret+=(arr[i]*arr[i]);
    }

    cout << ret << endl;

	return 0;
}

