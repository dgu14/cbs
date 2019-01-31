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

int n, a[450],b[450], asz, bsz, ff;
int dp[450][450][450];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // dp[i][j][k] i번째까지 봤을때 위에가 j번째, 아래가 k번ㅁ째까지 했을때 최대값
    // dp[i][j][k]는 i-1,j,k일수도 있고 j-1, k 또는 j-1 k-1 j, k-1일수도 있다.
    // 최대가 맞냐? i,j,k상태에서 최대는 위의 4개 중에서 존재할 수 밖에 없다.
    cin>>n;
    forn1(i,n)
    {
        cin>>ff; if(ff!=0) a[++asz]=ff;
    }

    forn1(i,n)
    {
        cin>>ff; if(ff!=0) b[++bsz]=ff;
    }

    forn(i,450) forn(j,450) forn(k,450) dp[i][j][k]=-INF;
    dp[0][0][0]=0;

    forn1(i,n)
    {
        forn(j,asz+1)
        {
            forn(k,bsz+1)
            {
                dp[i][j][k]=max({dp[i-1][j][k],(j!=0?dp[i-1][j-1][k]:-INF), (k!=0?dp[i-1][j][k-1]:-INF), (j!=0&&k!=0?dp[i-1][j-1][k-1]:-INF)+a[j]*b[k]});
            }
        }
    }

    cout << dp[n][asz][bsz] << endl;
	return 0;
}
