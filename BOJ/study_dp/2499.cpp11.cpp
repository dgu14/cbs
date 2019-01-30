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

int n, mp[22][22], sm[22][22], psum[80050][22];
bool dp[22][22][80050];
V<int> ret;

void solve(int i, int j, int k)
{
    if(i==0) return;

    int df=2*sm[i][j]-sm[i][n];

    for(int q=j;q<=n;q++)
    {
        if(dp[i-1][q][k-df])
        {
            solve(i-1,q,k-df);
            ret.push_back(n-j);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    forn(i,n)
    {
        forn(j,n)
        {
            cin>>mp[i][j];
        }
    }

    forn1(i,n)
    {
        sm[i][0]=0;
        forn1(j,n)
        {
            sm[i][j]=sm[i][j-1]+mp[j-1][i-1];
        }
    }

    dp[0][n][40025]=1;

    forn1(i,n)
    {
        memset(psum, 0, sizeof(psum));

        forn(j,80050)
        {
            psum[j][n]=dp[i-1][n][j];
            rforn(k,n)
            {
                psum[j][k]|=(psum[j][k+1] | dp[i-1][k][j]);
            }
        }

        forn(j,n+1)
        {
            forn(k,80050)
            {
                int df=2*sm[i][j]-sm[i][n];
                if(k-df>=0 && k-df<80050) dp[i][j][k]|=psum[k-df][j];
            }
        }
    }

    int mdf=INF, rj, rk;

    forn(i,n+1)
    {
        forn(j,80050)
        {
            if(dp[n][i][j])
            {
                if(mdf>abs(40025-j))
                {
                    mdf=abs(40025-j);
                    rj=i, rk=j;
                }
            }
        }
    }

    solve(n,rj,rk);

    cout << mdf << endl;

    forn(i,ret.size())
    {
        cout << ret[i] << ' ';
    }
    cout << endl;

	return 0;
}
