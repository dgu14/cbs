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

int n, a[10005], vst[10005], dp[10005][2][2];
V<int> adj[10005];

void dfs(int src)
{
    vst[src]=1;
    int s=0, d=0, m=0, m1=0, m2=0;

    for(int obj:adj[src])
    {
        if(!vst[obj])
        {
            dfs(obj);

            s+=dp[obj][0][1];
            d+=max(dp[obj][0][1], dp[obj][0][0]);
            m+=max(dp[obj][1][0], dp[obj][0][1]);
            if(m>m1) { m2=m1; m1=m; }
            else if(m>m2) m2=m;
        }
    }

    dp[src][0][0]=s;
    dp[src][0][1]=(m1==s?m2:m1);
    dp[src][1][0]=d+a[src];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>a[i]; int p,q;
    forn(i,n-1){ cin>>p>>q; adj[p].push_back(q); adj[q].push_back(p); }

    dfs(1);
    cout << max(dp[1][1][0], dp[1][0][1]) << endl;
	return 0;
}
