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

ll n,k;
ll dp[55], dp2[55][55];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    dp[0]=1;
    dp[1]=1; dp[2]=2;
    forn1(i,50)
    {
        if(i==1 || i==2) continue;
        dp[i]=dp[i-1]+dp[i-2];
    }

    forn1(i,50)
    {
        forn1(j,i)
        {
            ll a=0,b=0;

            forn(r,j)
            {
                a+=dp[r];
            }

            for(int r=j;r<=i;r++)
            {
                b+=dp[i-r];
            }

            dp2[i][j]=a*dp[i-j] + b*dp[j-1] - dp[i-j]*dp[j-1];
        }
    }

    cin>>n>>k;

    ll ret=0;
    // 고정석에 아무도 안 앉는다.
    ret+=dp[k-1]*dp[n-k];

    // 고정석에 i가 앉는다
    forn1(i,k-1)
    {
        ret+=dp[n-k]*dp2[k-1][i];
    }

    forn1(i,n-k)
    {
        ret+=dp[k-1]*dp2[n-k][i];
    }

    cout << ret << endl;


	return 0;
}
