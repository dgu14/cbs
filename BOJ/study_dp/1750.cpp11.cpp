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

int const MOD=10000003;
int n, arr[105], dp[105][100005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    forn(i,n) cin>>arr[i];

    /// dp[i][j]: i번째까지 봤을때, j의 최대 공약수를 가지는 갯수
    /// a,b,c의 최대 공약수는 gcd(c, gcd(a,b)) 와 같음을 이용

    forn(i,n)
    {

        forn(j,100001)
        {
            if(j==0)
            {
                dp[i][arr[i]]=(dp[i][arr[i]]+1)%MOD;
            }
            else
            {
                if(i==0) continue;
                dp[i][gcd(j, arr[i])]=(dp[i][gcd(j,arr[i])]+dp[i-1][j])%MOD;
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
        }
    }

    cout << dp[n-1][1] << endl;

	return 0;
}
