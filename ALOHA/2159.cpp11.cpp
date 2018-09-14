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

ll N,X,Y, x[100050], y[100050], dp[100050][5];
ll dx[]={0,0,0,1,-1}, dy[]={0,1,-1,0,0};

ll dist(ll s, ll ds, ll t, ll dt)
{
    if(t==0)
    {
        return abs(x[s]+dx[ds]-X)+abs(y[s]+dy[ds]-Y);
    }

    return abs(x[s]+dx[ds]-x[t]-dx[dt])+abs(y[s]+dy[ds]-y[t]-dy[dt]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>X>>Y; forn1(i,N) cin>>x[i]>>y[i];

    forn(i,N+1) forn(j,5) dp[i][j]=LONG_INF;


    dp[0][0]=0;
    forn1(i,N)
    {
        forn(j,5)
        {
            forn(k,5)
            {
                dp[i][j]=min(dp[i][j], dp[i-1][k]+dist(i,j, i-1,k));
            }
        }
    }

    ll min_t=LONG_INF;
    forn(i,5)
    {
        min_t=min(min_t, dp[N][i]);
    }

    cout << min_t << endl;

	return 0;
}

