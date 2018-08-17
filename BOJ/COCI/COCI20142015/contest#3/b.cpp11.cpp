#include <bits/stdc++.h>
using namespace std;

using ii=pair<int,int>;

int N,M,P;
int adj[100005];

int dfs(int src, bool& check, vector<bool>&visited)
{
    if(src==0) return 0;
    visited[src]=true;

    int ret =0;
    if(!visited[adj[src]]) ret = dfs(adj[src], check, visited) + 1;
    else check=false;
    return ret;
}

int main()
{
    cin>>N>>M>>P;

    int a,b;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b;

        if(!adj[b])
        adj[b]=a;
    }

    bool check=true;
    int ret;
    vector<bool> visited(100005, false);
    ret = dfs(P, check, visited);

    if(check)
    {
        cout << ret-1 << endl;
    }
    else cout << -1 << endl;

    return 0;
}
