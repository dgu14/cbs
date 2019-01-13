// 2014004193_choibeomseok_508
#include <algorithm>
#include <cstdio>
#include <vector>
#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n) for(int i=(int)n;i>0;i--)
#define INF         1000000007
using namespace std;

int n,a,b,m, cnt, p[1005];
vector<int> adj[1005];

void dfs(int src)
{
    p[src]=cnt;

    for(int i=0;i<adj[src].size();i++)
    {
        if(p[adj[src][i]]==0) dfs(adj[src][i]);
    }
}

int main()
{
    scanf("%d",&n);
    while(scanf("%d%d",&a,&b)!=-1)
    {
        if(a==0 && b==0) break;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        m++;
    }

    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }

    printf("%d\n", cnt);
    forn(i,n)
    {
        printf("%d\n", p[i]);
    }
    return 0;
}
