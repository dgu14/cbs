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

int n,m,a[1050][1050], dp[1050][1050];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,n) forn1(j,m) cin>>a[i][j];

    rforn1(i,n)
    {
        if(i==n)
        {
            rforn1(j,m)
            {
                dp[i][j]=dp[i][j+1]+a[i][j];
            }
            continue;
        }

        int sub1[1050]={0,}, sub2[1050]={0,};

        forn1(j,m)
        {
            if(j==1) sub1[j]=dp[i+1][j]+a[i][j];
            else sub1[j]=max(sub1[j-1], dp[i+1][j])+a[i][j];
        }

        rforn1(j,m)
        {
            if(j==m) sub2[j]=dp[i+1][j]+a[i][j];
            else sub2[j]=max(sub2[j+1], dp[i+1][j])+a[i][j];
        }

        forn1(j,m)
        {
            dp[i][j]=max(sub1[j], sub2[j]);
        }
    }

    cout << dp[1][1] << endl;

	return 0;
}

