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

int n, a[30], b[30];
int dp[25][300];


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];


    forn(i,n)
    {
        forn(j,101)
        {
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+a[i]]=max(dp[i+1][j+a[i]], dp[i][j]+b[i]);
        }
    }

    cout << dp[n][99] << endl;

	return 0;
}

