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


int n, a[5005], dp[5005][5005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    forn1(i,n) cin>>a[i];

    forn1(i,n)
    {
        forn1(j,n)
        {
            if(a[i]==a[n+1-j])
            {
                dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
            }

            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            dp[i][j+1]=max(dp[i][j+1], dp[i][j]);
        }
    }


    int sub=0;
    forn1(i,n+1) sub=max(sub, dp[n+1][i]), sub=max(sub, dp[i][n+1]);

    cout << n-sub <<endl;

	return 0;
}
