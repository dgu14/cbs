#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
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

ll const MOD=1e9+7;
ll dp[1050][2050];
lii ab[1050];
int n;

ll solve(ll d)
{
    // dp[i][j]: d보다 작거나 같으면서 i에서 끝나는, i를 포함한 cmax
    memset(dp, 0, sizeof(dp));

    for(int i=ab[0].first;i<=min(ab[0].second,d);i++)
    {
        dp[0][i+1020]++;
    }

    forn(i,n)
    {
        if(i==0) continue;

        ll psum[3050]={0,};
        psum[0]=dp[i-1][0];

        forn(j,3050)
        {
            if(j==0) continue;
            psum[j]=psum[j-1]+dp[i-1][j];
        }

        for(int j=ab[i].first;j<=d;j++)
        {
            int p=j-ab[i].first+1020, q=j-ab[i].second+1020;

            dp[i][j+1020]=(psum[p]-psum[max(1019, q-1)])%MOD;

            // 이전게 음수인 것들은 그냥 다 더해줘도 됨
            if(j<=ab[i].second) dp[i][j+1020]=(dp[i][j+1020]+psum[1019])%MOD;
        }
    }

    ll sm=0;
    forn(i,2050)
    {
        sm=(sm+dp[n-1][i])%MOD;
    }

    return sm;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--)
    {
        ll d;
        cin>>n>>d;

        forn(i,n)
        {
            cin>>ab[i].first>>ab[i].second;
        }

        ll sm1=solve(d);
        ll sm2=solve(d-1);

        cout << (MOD+sm1-sm2)%MOD << endl;
    }

	return 0;
}
