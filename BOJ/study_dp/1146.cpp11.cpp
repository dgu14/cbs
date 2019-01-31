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

ll const MOD=1000000;
ll dp[105], bino[105][105], n;

ll mod(ll a)
{
    return a%MOD;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // dp는 상대적인 크기로 이용
    // dp[i]-> dp[1] *dp[i-2] , dp[3] * dp[i-4] 다 더하기 답은 2*dp[i]


    forn1(i,100) bino[i][0]=bino[i][i]=1;
    bino[0][0]=1;

    forn1(i, 100)
    {
        forn1(j,i)
        {
            bino[i][j]=mod(bino[i-1][j-1]+bino[i-1][j]);
        }
    }

    cin>>n;

    dp[0]=1;
    dp[1]=1;
    forn1(i,n)
    {
        if(i==1) continue;
        for(int j=2;i-j>=0;j+=2)
        {
            dp[i]=mod(dp[i]+dp[i-j]*dp[j-1]*bino[i-1][j-1]);
        }
    }

    if(n==1) cout << dp[1] << endl;
    else cout << mod(2*dp[n]) << endl;

	return 0;
}
