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

// O(n * d^3)
ll n, cnt[55], str[55], d, dp[105][55][105];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>cnt[i]; forn1(i,n) cin>>str[i]; cin>>d;
    forn1(i,n) dp[1][i][0]=str[(i+1>n?n:i+1)]-str[i];

    // ith days
    forn1(i,d)
    {
        if(i==1) continue;
        // pmax
        ll pmax[105][55]={0,};
        forn1(j,i-1)
        {
            forn1(k,n)
            {
                if(k!=1) pmax[j][k]=pmax[j][k-1];

                forn(q,min(cnt[k],100ll))
                {
                    pmax[j][k]=max(pmax[j][k], dp[j][k][q]);
                }
            }
        }

        // for j level
        forn1(j,n)
        {
            // k sequentially
            forn(k,min(cnt[j],100ll))
            {
                forn(q,i)
                {
                    // i-q days spent, for j
                    ll diff=str[(j+i-q>n?n:j+i-q)]-str[j];

                    if(k==0) dp[i][j][k]=max(dp[i][j][k], (j==1?0:pmax[q][j-1])+diff);
                    else dp[i][j][k]=max(dp[i][j][k], dp[q][j][k-1]+diff);
                }
            }
        }
    }

    ll ori=0, mxdx=0;

    forn1(i,n)
    {
        ori+=cnt[i]*str[i];
    }

    forn1(i,d)
    {
        forn1(j,n)
        {
            forn(k,min(cnt[j],100ll)) mxdx=max(mxdx, dp[i][j][k]);
        }
    }

    cout << ori+mxdx << endl;

	return 0;
}
