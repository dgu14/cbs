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

int n,m,a[100005],psum[100005], dp[100005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,n)
    {
        cin>>a[i];
        psum[i]=psum[i-1]+a[i];
    }

    dp[m]=psum[m];

    for(int i=m+1;i<=n;i++)
    {
        if(dp[i-1]+a[i]>=psum[i]-psum[i-m])
        {
            dp[i]=dp[i-1]+a[i];
        }
        else dp[i]=psum[i]-psum[i-m];
    }

    int m_t=0;

    for(int i=m;i<=n;i++)
    {
        m_t=max(m_t, dp[i]);
    }

    cout << m_t << endl;
	return 0;
}
