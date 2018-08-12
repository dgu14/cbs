#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
class triple
{
public:
    int x,y,z;
};

int n,m,q;
triple e[100005], qry[100005];

int rk[100005], parent[100005], nsz[100005];

void init()
{
    for(int i=0;i<n;i++)
    {
        rk[i]=0;
        parent[i]=i;
        nsz[i]=1;
    }
}

int find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

void merge(int a, int b)
{
    int pa=find(a), pb=find(b);
    if(pa!=pb)
    {
        if(rk[pa]==rk[pb])
        {
            parent[pb]=pa;
            rk[pa]++;
            nsz[pa]=nsz[pa]+nsz[pb];
        }
        else if(rk[pa]>rk[pb])
        {
            parent[pb]=pa;
            nsz[pa]=nsz[pa]+nsz[pb];
        }
        else
        {
            parent[pa]=pb;
            nsz[pb]=nsz[pa]+nsz[pb];
        }
    }
}

int lo[100005], hi[100005], sz[100005], c[100005];
V<int> ttry[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>e[i].x>>e[i].y>>e[i].z;
        e[i].x--;e[i].y--;
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>qry[i].x>>qry[i].y;
        qry[i].z=i;qry[i].x--;qry[i].y--;
    }

    int d=1;
    for(int i=0;i<q;i++) hi[i]=m-1;
    sort(e, e+m, [](triple& a, triple&b)
         {
             return a.z < b.z;
         });

    while(d)
    {
        d=0;
        init();

        for(int i=0;i<q;i++)
        {
            if(lo[i] <= hi[i]) ttry[(lo[i]+hi[i])>>1].push_back(i);
        }

        for(int i=0;i<m;i++)
        {
            merge(e[i].x, e[i].y);

            while(ttry[i].size())
            {
                d=1;
                int idx=ttry[i].back();
                ttry[i].pop_back();

                if(find(qry[idx].x) == find(qry[idx].y))
                {
                    sz[idx]=nsz[find(qry[idx].x)];
                    c[idx]=e[i].z;
                    hi[idx]=i-1;
                }
                else lo[idx]=i+1;
            }
        }
    }

    for(int i=0;i<q;i++)
    {
        if(sz[i])
        {
            cout << c[i] << ' ' << sz[i] << '\n';
        }
        else cout << -1 << '\n';
    }

    return 0;
}
