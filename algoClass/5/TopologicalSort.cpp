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

vector<int> adj[2000], ret;
int vst[2000], fin[2000], cnt, bedg;

void dfs1(int src)
{
    vst[src]=1;

    for(int i=0;i<adj[src].size();i++)
    {
        if(!vst[adj[src][i]])
        {
            dfs1(adj[src][i]);
        }
        else if(fin[adj[src][i]]==0)
        {
            bedg=1;
        }
    }

    fin[src]=++cnt;
    ret.push_back(src);
}

int n,m,a,b;

int main()
{
    scanf("%d", &n);

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0 &&b==0) break;
        a--;b--;
        adj[a].push_back(b);
        m++;
    }

    forn(i,n)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    forn(i,n)
    {
        if(vst[i]==0) dfs1(i);
    }


    if(bedg==0)
    {
        reverse(ret.begin(), ret.end());
        printf("1\n");

        forn(i, ret.size())
        {
            printf("%d ", ret[i]+1);
        }
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
