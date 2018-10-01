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


int dp[105][105][3], a[105], b[105], asz, bsz;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--)
    {
        int C,D,d;
        cin>>C>>D>>d;

        forn(i,105) forn(j,105) forn(k,3) dp[i][j][k]=INF; asz=1; bsz=1;

        while(true)
        {
            cin>>a[asz++];
            if(a[asz-1]==0)
            {
                asz-=2; break;
            }
        }

        while(true)
        {
            cin>>b[bsz++];
            if(b[bsz-1]==0)
            {
                bsz-=2; break;
            }
        }

        dp[0][0][2]=0;

        forn(i, asz+1)
        {
            forn(j, bsz+1)
            {
                forn(k, 3)
                {
                    if(i+1<=asz) dp[i+1][j][0]=min(dp[i+1][j][0], dp[i][j][k]+(k==0?d:D+d)+C);
                    if(j+1<=bsz) dp[i][j+1][1]=min(dp[i][j+1][1], dp[i][j][k]+(k==1?d:D+d)+C);
                    if(i+1<=asz && j+1<=bsz) dp[i+1][j+1][2]=min(dp[i+1][j+1][2], dp[i][j][k]+(a[i+1]==b[j+1]?C:2*C));
                }
            }
        }

        int ret=INF;
        forn(i, 3) ret=min(ret, dp[asz][bsz][i]);
        cout << ret << '\n';
    }
	return 0;
}
