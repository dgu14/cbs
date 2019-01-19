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
V<int> adj[2][105];
int l[2][105];
int vst[105];

int dfs(int a, int idx)
{
    vst[a]=1;
    int ret=1;

    // dag, 역방향 간선 x, 트리간선 순방향 또는 크로스엣지
    // 해당 노드 밑에 있는 노드의 갯수를 세려면?
    // 트리간선이면 따로 더해줘야함.
    forn(i,adj[idx][a].size())
    {
        if(vst[adj[idx][a][i]]==0)
        {
            ret+=dfs(adj[idx][a][i], idx);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,m)
    {
        cin>>a>>b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    // dag로 나온다..
    // dfs로 자기보다 뒤에 있는것들을 쭉 빼낸다.

    forn1(i,n)
    {
        memset(vst, 0, sizeof(vst));
        l[0][i]=dfs(i, 0);
    }


    forn1(i,n)
    {
        memset(vst, 0, sizeof(vst));
        l[1][i]=dfs(i, 1);
    }

    int ret=0;

    forn1(i,n)
    {
        if(l[0][i]-1>=(n+1)/2 || l[1][i]-1>=(n+1)/2)
        {
            ret++;
        }
    }

    cout << ret << endl;

	return 0;
}
