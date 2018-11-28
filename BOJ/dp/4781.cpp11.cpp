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

int n,m, c[5005], p[5005], dp[20005];
int main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        int a,b;
        scanf("%d%d.%d", &n, &a, &b);
        m=100*a+b;

        if(n==0 && m==0) break;

        forn(i,n)
        {
            scanf("%d%d.%d", &c[i], &a, &b);
            p[i]=100*a+b;
        }

        memset(dp, 0, sizeof(dp));

        // dp
        forn(i,m+1)
        {
            forn(j,n)
            {
                dp[i+p[j]]=max(dp[i+p[j]], dp[i]+c[j]);
            }
        }

        printf("%d\n", dp[m]);
    }

	return 0;
}
