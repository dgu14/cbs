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

int const MOD=998244353;
int n,k, dp[1005][2005][4];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;

    dp[1][1][0]=dp[1][1][3]=1;
    dp[1][2][1]=dp[1][2][2]=1;

    forn(i,n)
    {
        if(i==0) continue;
        forn1(j,k)
        {
            forn(r,4)
            {
                forn(q,4)
                {
                    if(q==0 || q==3)
                    {
                        dp[i+1][j+(bitcount(r^q)==2?1:0)][q]=(dp[i+1][j+(bitcount(r^q)==2?1:0)][q]+dp[i][j][r])%MOD;
                    }
                    else dp[i+1][j+bitcount(r^q)][q]=(dp[i+1][j+bitcount(r^q)][q]+dp[i][j][r])%MOD;
                }
            }
        }
    }

    int ret=0;

    forn(i,4)
    {
        ret=(ret+dp[n][k][i])%MOD;
    }

    cout << ret << endl;

	return 0;
}

