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

int n, dp[51][500001], a[51];
int const zero=250000;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>a[i]; sort(a+1, a+n+1);

    forn(i,51) forn(j,500001) dp[i][j]=-1;


    dp[0][zero]=0;
    forn1(i,n)
    {
        forn(j,500001)
        {
            if(j-a[i]>=0 && dp[i-1][j-a[i]]!=-1) dp[i][j]=max(dp[i][j], dp[i-1][j-a[i]]+a[i]);
            if(j+a[i]<=500000 && dp[i-1][j+a[i]]!=-1) dp[i][j]=max(dp[i][j], dp[i-1][j+a[i]]);
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }


    if(dp[n][zero]==-1 || dp[n][zero]==0) cout << -1 << endl;
    else cout << dp[n][zero] << endl;

	return 0;
}


/*
6
400000 12500 12500 12500 12500 5
-1

아 존나 멍청하다 진짜
처음에 거를 왜 무조건 택한다고 가정하냐 멍청아.
진짜
*/
