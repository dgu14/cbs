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

int n;
lii xy[10005];
ll dp[10005];

ll ydiff(ll my, ll ny)
{
    if(my<0) my=-my;
    if(ny<0) ny=-ny;

    return max(my,ny);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn(i,n) cin>>xy[i].first>>xy[i].second;
    sort(xy, xy+n);

    // dp[i]=dp[i-k]+sdf , sdf는 i와 j+1까지의 거리
    // i와 j+1이 같다면 y좌표 만큼.
    // 다르면 왼쪽 끝에서 오른쪽 끝 과 최대 y 최소 y 중 최대

    forn(i,10005) dp[i]=LONG_INF;

    forn(i,n)
    {
        ll my=-INF,ny=INF;
        rforn(j,i)
        {
            my=max(my, xy[j+1].second); ny=min(ny, xy[j+1].second);
            ll sdf=max(xy[i].first-xy[j+1].first, 2*ydiff(my,ny));
            dp[i]=min(dp[i], dp[j]+sdf);
        }

        my=max(my, xy[0].second); ny=min(ny, xy[0].second);
        dp[i]=min(dp[i], max(xy[i].first-xy[0].first, 2*ydiff(my,ny)));
    }

    cout << dp[n-1] << endl;

	return 0;
}
