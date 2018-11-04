/// 2014004193_ÃÖ¹ü¼®_508
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n) for(int i=(int)n;i>0;i--)
#define INF         1000000007
using namespace std;
typedef pair<int,int> ii;

int n, cnt[30005], tot, nodeCnt, parent[100000], pcnt[100000], ret;
string str[30005];

int dfs(int src)
{
    if(pcnt[src]) return pcnt[src];

    if(parent[src]!=-1) return pcnt[src]=dfs(parent[src])+1;
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n;

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    forn(i,100000) parent[i]=-1;
    forn(i,n)
    {
        cin>>str[i]>>cnt[i];
        pq.push({cnt[i], i});
    }
    cin>>tot;
    nodeCnt=n;

    // fixed-length code
    int m=n, mb;
    while(m)
    {
        mb=m&-m;
        m-=mb;
    }

    mb=log2(mb)+1;
    cout << mb*tot << endl;

    // merging
    while(pq.size()>1)
    {
        ii t1=pq.top(); pq.pop();
        ii t2=pq.top(); pq.pop();

        int ps=t1.first+t2.first;
        parent[t1.second]=nodeCnt;
        parent[t2.second]=nodeCnt;

        pq.push({ps, nodeCnt});
        nodeCnt++;
    }

    for(int i=0;i<n;i++)
    {
        ret+=dfs(i) * cnt[i];
    }

    cout << ret << endl;

    return 0;
}

/*
6
ffff 5000
eeee 9000
cccc 12000
bbbb 13000
dddd 16000
aaaa 45000
100000
*/
