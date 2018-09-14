#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

int n,k, a[55000], dp[4][55000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>a[i]; cin>>k;

    forn1(i,n)
    {
        dp[0][i]=dp[0][i-1]+a[i];
    }

    forn1(i, 3)
    {
        if(i==1)
        {
            forn1(j,n) if(j-k>=0) dp[1][j]=max(dp[1][j-1], dp[0][j]-dp[0][j-k]);
            continue;
        }

        forn1(j, n)
        {
            if(j-k>=0) dp[i][j]=max(dp[i][j-1], dp[i-1][j-k] + dp[0][j]-dp[0][j-k]);
        }
    }

    cout << dp[3][n] <<endl;

	return 0;
}


