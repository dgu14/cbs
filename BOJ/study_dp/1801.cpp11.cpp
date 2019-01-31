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

int n, arr[20];
bool dp[17][41][41][81][81];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    forn1(i,n) cin>>arr[i];

    dp[0][0][0][0][0]=1;
    forn1(i,n)
    {
        forn(j,41)
        {
            forn(k,41)
            {
                forn(r,81)
                {
                    forn(q,81)
                    {
                        if(j+arr[i]<=40) dp[i][j+arr[i]][k][r][q]|=dp[i-1][j][k][r][q];
                        if(k+arr[i]<=40) dp[i][j][k+arr[i]][r][q]|=dp[i-1][j][k][r][q];
                        if(r+arr[i]<=80) dp[i][j][k][r+arr[i]][q]|=dp[i-1][j][k][r][q];
                        if(q+arr[i]<=80) dp[i][j][k][r][q+arr[i]]|=dp[i-1][j][k][r][q];
                        dp[i][j][k][r][q]|=dp[i-1][j][k][r][q];
                    }
                }
            }
        }
    }

    int ret=-INF;

    forn1(i,40)
    {
        forn1(j,40)
        {
            if(dp[n][i][i][j][j])
            {
                ret=max(ret, i*j);
            }
        }
    }

    if(ret==-INF)
    {
        cout << -1 << endl;
    }
    else cout << ret << endl;

	return 0;
}
