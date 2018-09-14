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

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt;
    cin>>tt;

    int dp[101][101][2]={0,};


    dp[1][0][0]=dp[1][0][1]=1;
    forn1(i, 100)
    {
        if(i==1) continue;
        forn(j, 100)
        {
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1]=(j==0?0:dp[i-1][j-1][1])+dp[i-1][j][0];
        }
    }

    while(tt--)
    {
        int n,k;
        cin>>n>>k;

        cout <<dp[n][k][0]+dp[n][k][1] <<'\n';
    }


	return 0;
}
