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

int l,k,c,arr[10005];

bool possible(int len)
{
    int ret=0;
    int pr=0;

    forn(i,k)
    {
        if(arr[i]-arr[pr]>len)
        {
            pr=i-1;

            if(arr[i]-arr[pr]>len) return false;
            ret++;
        }
    }

    return ret<=c;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>l>>k>>c;
    arr[0]=0;
    forn1(i,k) cin>>arr[i];
    arr[k+1]=l;
    k=k+2;

    sort(arr, arr+k);

    int lo=0, hi=1000000000;
    int mid, ret;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        if(possible(mid))
        {
            ret=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    int ll;

    int rrt=0;
    int rpr=k-1;

    rforn(i,k)
    {
        if(arr[rpr]-arr[i]>ret)
        {
            rpr=i+1;
            rrt++;
        }
    }

    if(rrt<c)
    {
        rpr=1;
    }

    cout << ret << " " << arr[rpr] << endl;
	return 0;
}
