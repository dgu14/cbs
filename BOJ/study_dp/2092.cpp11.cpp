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

/// O(a^2)

/// dp[i][j][k]: i개를 써서, 마지막 원소가 j를 k번썼을 때 갯수
/// if(k==1) -> dp[i-1][q<j][all]의합을 더해준다 -> psum을 활용
/// else dp[i-1][j][k-1]에서 더해준다

int const MOD=1e6;
int t,a,s,b,c, f[205];
V<int> dp[4050][205];

int mod(int a)
{
    return a%MOD;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>t>>a>>s>>b;

    forn(i,a)
    {
        cin>>c;
        f[c]++;
    }

    forn(i,4050)
    {
        forn(j,205)
        {
            dp[i][j]=V<int> (f[j], 0);
        }
    }

    forn(i,205)
    {
        if(f[i]) dp[1][i][0]=1;
    }

    forn1(i,a)
    {
        if(i==1) continue;
        int psum[205]={0,};
        forn(j,205)
        {
            if(j==0) continue;

            int sm=0;
            forn(k,f[j]) sm=mod(sm+dp[i-1][j][k]);
            psum[j]=mod(psum[j-1]+sm);
        }

        forn(j,205)
        {
            if(j==0) continue;
            forn(k,f[j])
            {
                if(k==0)
                {
                    dp[i][j][k]=mod(psum[j-1]+dp[i][j][k]);
                }
                else dp[i][j][k]=mod(dp[i-1][j][k-1]+dp[i][j][k]);
            }
        }
    }

    int ret=0;

    for(int i=s;i<=b;i++)
    {
        forn(j,205)
        {
            forn(k,f[j])
            {
                ret=mod(dp[i][j][k]+ret);
            }
        }
    }

    cout << ret << endl;

	return 0;
}
