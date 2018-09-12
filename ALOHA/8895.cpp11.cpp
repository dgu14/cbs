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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tt;
    cin>>tt;


    ll dp[30][30][30]={0,}, C[21][21]={0,};
    dp[1][1][1]=1;
    dp[0][0][0]=1;

    forn(i,21) C[i][0]=C[i][i]=1;
    forn1(i,20)
    {
        forn1(j,20)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }

    forn1(i,20)
    {
        if(i==1) continue;
        forn1(j,i)
        {
            forn1(k,i)
            {
                forn(q,i)
                {
                    forn(u,21)
                    {
                        forn(v,21)
                        {
                            dp[i][j][k]+=dp[q][j-1][u]*dp[i-1-q][v][k-1]*C[i-1][q];
                        }
                    }
                }
            }
        }
    }

    while(tt--)
    {
        int n,l,r;
        cin>>n>>l>>r;

        cout << dp[n][l][r] << endl;

    }

	return 0;
}
