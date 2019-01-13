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

typedef pair<int,int> ii;
typedef pair<int,ii> edg;
int n,m,a,b,c, prnt[1005];

vector<edg> edges;
void init()
{
    forn(i,n) prnt[i]=i;
}

int fnd(int a)
{
    if(prnt[a]==a) return a;
    else return prnt[a]=fnd(prnt[a]);
}

int mrg(int a, int b)
{
    int pa=fnd(a), pb=fnd(b);
    if(pa!=pb)
    {
        prnt[pa]=pb;
        return 1;
    }

    return 0;
}

int main()
{
    scanf("%d",&n);
    while(scanf("%d%d%d",&a,&b,&c)!=-1)
    {
        if(a==0 && b==0 && c==0) break;
        m++;

        if(a>b) swap(a,b);
        edges.push_back({c,{a,b}});
    }

    init();
    sort(edges.begin(), edges.end());
    vector<int> selected;

    forn(i,m)
    {
        if(mrg(edges[i].second.first, edges[i].second.second))
        {
            selected.push_back(i);
        }
    }

    printf("%d\n", selected.size());
    forn(i,selected.size())
    {
        printf("%d %d %d\n", edges[selected[i]].second.first, edges[selected[i]].second.second,
               edges[selected[i]].first);
    }

    return 0;
}

/*
9
2 3 8
3 9 2
4 5 9
4 6 14
1 2 4
5 6 10
2 8 11
6 7 2
7 9 6
8 9 7
4 3 7
1 8 8
8 7 1
3 6 4
*/
