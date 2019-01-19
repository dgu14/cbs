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

int n,m,a,b,c;
int dp[250][250], w[250][250];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,250)
    {
        forn(j,250)
        {
            if(i==j)
            {
                dp[i][j]=0;
            }
            else dp[i][j]=INF;
        }
    }

    forn(i,m)
    {
        cin>>a>>b>>c;
        a--;b--;

        dp[a][b]=c;
        dp[b][a]=c;
    }


    forn(i,250)
    {
        forn(j,250)
        {
            if(i==j) w[i][j]=-1;
            else w[i][j]=j;
        }
    }

    // floyd
    forn(i,n)
    {
        forn(j,n)
        {
            forn(k,n)
            {
                if(dp[j][k]>dp[j][i]+dp[i][k])
                {
                    dp[j][k]=dp[j][i]+dp[i][k];
                    w[j][k]=w[j][i];
                }
            }
        }
    }

    forn(i,n)
    {
        forn(j,n)
        {
            if(i==j)
            {
                cout<<'-'<< ' ';
            }
            else
            {
                cout << w[i][j]+1 << ' ';
            }
        }
        cout << '\n';
    }

	return 0;
}

