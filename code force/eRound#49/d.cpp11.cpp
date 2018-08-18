#include <bits/stdc++.h>
using namespace std;

int n, c[200005], a[200005];

vector<bool> done, visited;

int dfs2(int src,vector<bool>& v2, int mx)
{
    v2[src]=true;
    mx=min(mx, c[src]);

    if(v2[a[src]]) return mx;
    else return dfs2(a[src], v2, mx);
}

int dfs(int src)
{
    if(done[src])
    {
        return 0;
    }

    if(visited[src])
    {
        vector<bool> v2(200005, false);
        return dfs2(src,v2, 999999999);
    }

    visited[src]=true;
    return dfs(a[src]);
}

void dfs3(int src)
{
    if(done[src]) return;
    done[src]=true;

    dfs3(a[src]);
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    done=vector<bool>(n,false);
    visited=vector<bool>(n,false);

    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            ret+=dfs(i);
            dfs3(i);
        }
    }

    cout << ret << endl;

    return 0;
}
