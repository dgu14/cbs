#include <bits/stdc++.h>
using namespace std;

int n, parent[500005], dgr[500005], r[500005];
// 1 mafia, 2 citizen, 0 ?

void dfs(vector<bool>& visited, int x, int p)
{
    if(r[x]!=2) r[x] = p;
    visited[x] = true;

    if(!visited[parent[x]]) dfs(visited, parent[x], ((r[x]==2)?1:2));
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> parent[i];

        dgr[i]++;
        dgr[parent[i]]++;
    }

    queue<int> q;
    vector<bool> visited(n+1, false);
    for(int i=1;i<=n;i++)
    {
        if(dgr[i] == 1)
        {
            q.push(i);
            r[i] = 1;
        }
    }


    while(q.size())
    {
        int here = q.front(); q.pop();
        visited[here] = true;

        dgr[parent[here]]--;
        if(r[here] == 1) r[parent[here]] = 2;

        if(dgr[parent[here]] == 1)
        {
            if(r[parent[here]] != 2) r[parent[here]] = 1;
            q.push(parent[here]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && r[i] == 2)
        {
            dfs(visited, i, 2);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(visited, i, 2);
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(r[i] == 1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
