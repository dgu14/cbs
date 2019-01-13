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

int n,m, arr[20000], ret;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // right after left
    cin>>n>>m;
    forn(i,n) cin>>arr[i];

    sort(arr, arr+n);
    int pos=-1;
    forn(i,n) if(arr[i]>=0)
    {
        pos=i;
        break;
    }

    if(pos==-1) pos=n;
    int g=(pos+m-1)/m;
    int k=0;
    forn(i,g)
    {
        ret+=-arr[k]*2;
        k+=m;
    }

    k=n-1;
    pos=n-pos;
    g=(pos+m-1)/m;

    forn(i,g)
    {
        ret+=arr[k]*2;
        k-=m;
    }

    ret-=max(abs(arr[0]), abs(arr[n-1]));

    cout << ret << endl;


	return 0;
}

