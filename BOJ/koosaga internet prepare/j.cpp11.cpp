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


int n, m;

bool compare(int dp[][15][10], int i, int j, int k, int q)
{
    for(int r=9;r>=0;r--)
    {
        int a=dp[i][j][r]?1:0, b=dp[k][q][r]?1:0;
        if(a==b) continue;
        else if(a>b) return true;
        else return false;
    }

    return false;
}

int main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(scanf("%d", &n)!=EOF)
    {
        scanf("%d", &m);

        int mp[15][15]; int dp[15][15][10]={0,}, cnt[15][15]={0, };
        forn(i,n) forn(j,n) scanf("%d", &mp[i][j]);


        forn(i,n)
        {
            forn(j,n)
            {
                forn(k,m)
                {
                    forn(q,m)
                    {
                        if(i+k<n && j+q<n)
                        {
                            dp[i][j][mp[i+k][j+q]]++;
                            if(dp[i][j][mp[i+k][j+q]]==1) cnt[i][j]++;
                        }
                    }
                }
            }
        }

        int rx=0,ry=0;

        forn(i,n)
        forn(j,n)
        if(i+m-1<n && j+m-1<n)
        {
            if(i==0 && j==0) continue;
            if(cnt[i][j]<cnt[rx][ry] || (cnt[i][j]==cnt[rx][ry] && compare(dp, i,j,rx,ry)))
            {
                rx=i; ry=j;
            }
        }

        cout << rx+1 << ' ' << ry+1  << '\n';
    }


	return 0;
}

