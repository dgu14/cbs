#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii=pair<ll,ll>;
template <class T> using V = vector<T>;
ll n,q;
V<ii> chkpnt;
V<ii> xs, ys;

map<ii, ll> mdist;
map<ii, bool>exist;
void precalc()
{
    //x
    for(int i=1;i<n;i++)
    {
        int ta = xs[i-1].second, tb=xs[i].second;
        if(ta > tb) swap(ta , tb);

        if(!exist[{ta,tb}])
        {
            mdist[{ta,tb}]=xs[i].first-xs[i-1].first;
            exist[{ta,tb}]= true;
        }
        else mdist[{ta,tb}] = min(mdist[{ta,tb}], xs[i].first-xs[i-1].first);
    }

    //y
    for(int i=1;i<n;i++)
    {
        int ta = ys[i-1].second, tb=ys[i].second;
        if(ta > tb) swap(ta , tb);
        if(!exist[{ta,tb}])
        {
            mdist[{ta,tb}]=ys[i].first-ys[i-1].first;
            exist[{ta,tb}]=true;
        }
        else mdist[{ta,tb}] = min(mdist[{ta,tb}], ys[i].first-ys[i-1].first);
    }
}


class DisjointSet
{
public:
    V<int> parent, rank;

    DisjointSet(int n)
    {
        parent=V<int>(n); rank=V<int>(n, 0);
        for(int i=0;i<n;i++ ) parent[i] =i;
    }

    int find(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b)
    {
        int pa=find(a);
        int pb=find(b);

        if(pa == pb) return;

        if(rank[pa] == rank[pb])
        {
            rank[pa]++;
            parent[pb] = pa;
        }
        else if(rank[pa] > rank[pb])
        {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
    }
};
class triple
{
public:
    ll x,y,z;
};
class quad
{
public:
    ll x,y,z,u;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    chkpnt=V<ii>(n);
    xs=V<ii>(n);
    ys=V<ii>(n);
    for(int i=0;i<n;i++)
    {
        cin >> chkpnt[i].first >> chkpnt[i].second;
        xs[i] = {chkpnt[i].first,i}; ys[i] = {chkpnt[i].second, i};
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    precalc();


    V<quad> query(q);
    for(ll i=0;i<q;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;

        query[i] = {c,a,b, i};
    }

    sort(query.begin(), query.end(), [](quad a, quad b)
         {
             return a.x < b.x;
         });


    V<triple> edges;
    V<int>answer(q);
    for(auto it=mdist.begin();it!=mdist.end();it++)
    {
        edges.push_back({it->second, it->first.first, it->first.second});
    }

    sort(edges.begin(), edges.end(), [](triple a, triple b)
         {
             return a.x < b.x;
         });


    DisjointSet djs(n);

    int j=0;
    for(int i=0;i<q;i++)
    {
        ll ta = query[i].y, tb=query[i].z;

        while(j<edges.size() && query[i].x >= edges[j].x)
        {
            djs.merge(edges[j].y, edges[j].z);
            j++;
        }

        if(djs.find(ta) == djs.find(tb))
        {
            answer[i] = 1;
        }
        else answer[i] = 0;
    }

    V<int> realRet(q);
    for(int i=0;i<q;i++)
    {
        realRet[query[i].u] = answer[i];
    }

    for(int i=0;i<q;i++)
    {
        if(realRet[i])
        {
            cout << "YES" <<'\n';
        }
        else cout << "NO" <<'\n';
    }
    cout << endl;

    return 0;
}
