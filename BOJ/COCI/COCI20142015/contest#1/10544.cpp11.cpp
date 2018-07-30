#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ll = long long;
using ii = pair<ll,ll>;

int n,k;
V<V<ii>> adj;
V<bool> isDest, isInternal;
V<ll> distToCloseInternal,mostFarFromHereInternal, far, depth, nDepth;
V<int> closeInternal;
ll w;


int dfs(int root, V<bool>& visited)
{
    visited[root] = true;

    int ret = isDest[root]?1:0;
    for(ii there : adj[root])
    {
        if(!visited[there.first])
        {
            ret += dfs(there.first, visited);
        }
    }

    if(ret != 0) isInternal[root] = true;
    return ret;
}


void dfs2(int root, V<bool>& visited, ll d, int prev)
{
    visited[root] = true;
    if(isInternal[root])
    {
        d = 0;
        prev = root;
    }
    else
    {
        distToCloseInternal[root] = d;
    }

    closeInternal[root] = prev;

    for(ii there : adj[root])
    {
        if(!visited[there.first])
        {
            if(isInternal[there.first]) w += there.second;
            dfs2(there.first, visited, d+there.second, prev);
        }
    }
}

ll dfs3(int root, V<bool>& visited)
{
    visited[root] = true;
    ll& m1 = depth[root];
    ll& m2 = nDepth[root];
    ll& way = far[root];

    for(ii there : adj[root])
    {
        if(!visited[there.first] && isInternal[there.first])
        {
            ll val = dfs3(there.first, visited) + there.second;
            if(val > m1)
            {
                m2 = m1;
                m1 = val;
                way = there.first;
            }
            else if(val > m2)
            {
                m2 = val;
            }
        }
    }

    return m1;
}

void dfs4(int root, V<bool>& visited, ll anc)
{
    visited[root] = true;
    mostFarFromHereInternal[root] = max(depth[root], anc);

    for(ii there : adj[root])
    {
        if(!visited[there.first] && isInternal[there.first])
        {
            if(far[root] == there.first)
            {
                dfs4(there.first, visited, max(anc+there.second, nDepth[root]+there.second));
            }
            else
            {
                dfs4(there.first, visited, max(anc+there.second, depth[root]+there.second));
            }
        }
    }
}

ll solve(int srtNode)
{
    return distToCloseInternal[srtNode] + 2 * w - mostFarFromHereInternal[closeInternal[srtNode]];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    adj=V<V<ii>> (n); isInternal = V<bool>(n, 0); isDest=V<bool>(n, 0);
    distToCloseInternal = V<ll> (n,0); mostFarFromHereInternal = V<ll>(n,0);
    closeInternal=V<int>(n,0);
    depth=V<ll>(n,0); nDepth=V<ll>(n,0); far=V<ll>(n,-1);
    int a,b,c;
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b >> c;
        a--; b--;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int root = -1;

    for(int i=0;i<k;i++)
    {
        cin >> a;
        a--;
        isDest[a] = true;

        if(root == -1) root = a;
    }

    V<bool> visited(n, false);
    dfs(root, visited);
    fill(visited.begin(), visited.end(), false);
    dfs2(root, visited, 0, root);
    fill(visited.begin(), visited.end(), false);
    dfs3(root, visited);
    fill(visited.begin(), visited.end(), false);
    dfs4(root, visited, 0);


    for(int i=0;i<n;i++) cout << solve(i) << '\n';

    return 0;
}
