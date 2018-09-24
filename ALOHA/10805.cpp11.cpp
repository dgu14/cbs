#include<bits/stdc++.h>
using namespace std;

template <class T, class Q> class duo {public: T x; Q y; bool operator<(duo<T,Q> const& rhs){ return (x==rhs.x?y<rhs.y:x<rhs.x); }};
template <class T, class Q, class U> class triple {public: T x; Q y; U z; bool operator<(triple<T,Q,U> const& rhs){ return (x==rhs.x?(y==rhs.y?z<rhs.z:y<rhs.y):x<rhs.x);}};
template <class T> using V=vector<T>;

using ll=long long;
using dbl=double;
using ii=duo<int,int>;
using lii=duo<ll,ll>;
using iii=triple<int,int,int>;
using liii=triple<ll,ll,ll>;
using dii=duo<dbl,dbl>;
using diii=triple<dbl,dbl,dbl>;

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

int dp[60][60][60][60];
int dp2[60][60];

int precalc()
{
    for(int i=1;i<60;i++)
    {
        for(int j=1;j<60;j++)
        {
            if(i==j) dp2[i][j]=1; else dp2[i][j]=INF;


            for(int k=1;k<j;k++)
            {
                dp2[i][j]=min(dp2[i][j],dp2[i][j-k]+dp2[i][k]);
            }
            for(int k=1;k<i;k++)
            {
                dp2[i][j]=min(dp2[i][j], dp2[i-k][j]+dp2[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;

    precalc();

    for(int i=2;i<=h1;i++)
    {
        for(int j=2;j<=w1;j++)
        {
            for(int p=1;p<i;p++)
            {
                for(int q=1;q<j;q++)
                {
                    dp[i][j][p][q]=INF;
                    for(int x=1;x<p;x++)
                    {
                        dp[i][j][p][q]=min(dp[i][j][p][q], dp[i-x][j][p-x][q]+dp2[x][j-q]);
                    }

                    for(int x=1;x<i-p;x++)
                    {
                        dp[i][j][p][q]=min(dp[i][j][p][q], dp[i-x][j][p][q]+dp2[x][j]);
                    }

                    for(int x=1;x<q;x++)
                    {
                        dp[i][j][p][q]=min(dp[i][j][p][q], dp[i][j-x][p][q-x]+dp2[x][i-p]);
                    }

                    for(int x=1;x<j-q;x++)
                    {
                        dp[i][j][p][q]=min(dp[i][j][p][q], dp[i][j-x][p][q]+dp2[x][i]);
                    }

                    dp[i][j][p][q]=min(dp[i][j][p][q], dp2[j-q][p]+dp2[j][i-p]);
                    dp[i][j][p][q]=min(dp[i][j][p][q], dp2[i][j-q]+dp2[i-p][q]);
                }
            }
        }
    }

    cout << dp[h1][w1][h2][w2] << endl;
	return 0;
}

