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

int n, w[10005], dp[10005][2], vst[10005];
V<int> adj[10005];

void dfs(int src)
{
    vst[src]=1;
    dp[src][1]=w[src];

    for(int obj:adj[src])
    {
        if(!vst[obj])
        {
            dfs(obj);
            dp[src][0]+=max(dp[obj][0], dp[obj][1]);
            dp[src][1]+=dp[obj][0];
        }
    }
}

V<int> l;
void print(int src, int sel)
{
    if(sel==1) l.push_back(src);
    vst[src]=1;

    for(int obj:adj[src])
    {
        if(!vst[obj])
        {
            if(sel==1) print(obj, 0);
            else print(obj, (dp[obj][0]>dp[obj][1]?0:1));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>w[i]; int a,b;
    forn(i,n-1) { cin>>a>>b; adj[a].push_back(b); adj[b].push_back(a); }

    dfs(1); memset(vst, 0, sizeof(vst));
    cout << max(dp[1][0], dp[1][1]) << endl;

    print(1, (dp[1][0]>dp[1][1]?0:1));
    sort(l.begin(), l.end());

    forn(i, l.size())
    {
        cout << l[i];
        if(i!=l.size()-1) cout << ' ';
        else cout << endl;
    }

	return 0;
}

