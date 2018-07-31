#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;

int n,m,q,a,b;

class DisJointSet
{
public:
    V<int> rank;
    V<int> parent;

    DisJointSet(int n)
    {
        rank = V<int> (n, 0);
        parent = V<int> (n);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }

    int find(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if(rank[pa] == rank[pb])
        {
            parent[pa]=pb;
            rank[pb]++;
        }
        else if(rank[pa] > rank[pb])
        {
            parent[pb]=pa;
        }
        else
        {
            parent[pa]=pb;
        }
    }
};

int main()
{
    cin>>n>>m>>q;
    DisJointSet djs(n+m);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        a--; b--;

        djs.merge(a,b+n);
    }

    set<int> s;
    for(int i=0;i<n+m;i++)
    {
        s.insert(djs.find(i));
    }

    cout << s.size()-1 << endl;

    return 0;
}
