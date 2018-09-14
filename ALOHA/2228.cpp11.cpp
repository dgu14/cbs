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

int n,m, arr[150], dp[150][150];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,n) cin>>arr[i];

    forn(i, 150) forn(j,150) dp[i][j]=-9999999;

    dp[0][0]=0;
    forn1(i,n) dp[i][0]=arr[i];

    forn1(i,n)
    {
        forn(j,m+1)
        {
            if(dp[i-1][j]!=-9999999) dp[i][j]=max(dp[i][j], dp[i-1][j]+arr[i]);

            forn1(k, i-2)
            {
                if(dp[k][j-1]!=-9999999) dp[i][j]=max(dp[i][j],dp[k][j-1]+arr[i]);
            }
        }
    }

    int max_t=-9999999;
    forn1(i,n)
    {
        max_t=max(max_t, dp[i][m-1]);
    }

    cout <<max_t<<endl;

	return 0;
}

