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

// O(NT)

int n,t, a[105], dp[105][20050], s[105][20050]; V<int> ret;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>t; forn1(i,n) cin>>a[i];

    dp[2][a[1]-a[2]+10025]=1;
    s[2][a[1]-a[2]+10025]=0;
    forn1(i,n)
    {
        if(i==1 || i==n) continue;
        forn1(j,20050)
        {
            if(dp[i][j])
            {
                dp[i+1][j+a[i+1]]=1, s[i+1][j+a[i+1]]=1;
                dp[i+1][j-a[i+1]]=1, s[i+1][j-a[i+1]]=0;
            }
        }
    }

    rforn1(i,n)
    {
        if(i==1) break;
        ret.push_back(s[i][t+10025]);

        if(s[i][t+10025]) t-=a[i];
        else t+=a[i];
    }
    reverse(ret.begin(), ret.end());

    int f=0;
    forn(i,ret.size())
    {
        if(ret[i]==1) cout << i+1-f << '\n', f++;
    }

    forn(i,n-1-f)
    {
        cout << 1 << '\n';
    }

	return 0;
}
