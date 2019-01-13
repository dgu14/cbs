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

int n;
int a[101], b[101];
int aa[101], bb[101];

int maximal(int sz)
{
    int mx=-1;
    int ap=0, bp=100;
    memcpy(aa, a, sizeof(a));
    memcpy(bb, b, sizeof(b));

    while(true)
    {
        while(ap<=100 && aa[ap]==0) ap++;
        while(bp>=0 && bb[bp]==0) bp--;

        if(ap==101 || bp==-1) break;
        int tmp=min(aa[ap], bb[bp]);
        aa[ap]-=tmp;
        bb[bp]-=tmp;

        mx=max(mx, ap+bp);
    }

    return mx;
}

int main()
{
    scanf("%d", &n);
    int t,q,sz=0;
    forn(i,n)
    {
        scanf("%d%d", &t, &q);
        a[t]++;
        b[q]++;
        printf("%d\n", maximal(++sz));
    }

	return 0;
}
