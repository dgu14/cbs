#include <bits/stdc++.h>
using namespace std;

int const MAX_N=1e6;
int n, m, a[MAX_N], b[MAX_N], s[2*MAX_N],p[2*MAX_N], as[2*MAX_N], bs[2*MAX_N], ans;

void init()
{
    for(int i=0;i<2*MAX_N;i++)
    {
        p[i]=i; as[i]=0; bs[i]=1;
    }
}

int find(int r){ if(p[r]==r) return r; return p[r]=find(p[r]); }
void merge(int r, int l)
{
    int pr=find(r), pl=find(l);
    if(pr!=pl)
    {
        p[pr]=pl;
        if(bs[pl]==1 || bs[pr]==1) as[pl]=max(as[pl], as[pr])+1;
        else as[pl]+=as[pr]+1;

        bs[pl]+=bs[pr];
    }
    else
    {
        as[pl]+=1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        s[m++]=a[i]; s[m++]=b[i];
    }

    sort(s, s+m);
    m=unique(s, s+m)-s;

    for(int i=0;i<n;i++)
    {
        a[i]=lower_bound(s, s+m, a[i])-s;
        b[i]=lower_bound(s, s+m, b[i])-s;
    }

    init();
    for(int i=0;i<n;i++)
    {
        merge(a[i], b[i]);
        int pa=find(a[i]);

        //cout << as[pa] << ", " << bs[pa] << endl;
        if(as[pa]>bs[pa])
        {
            cout << -1 << endl;
            return 0;
        }
    }


    for(int i=0;i<m;i++)
    {
        int pi=find(i);
        if(as[pi]) { ans=max(ans, s[i]); as[pi]--; }
    }


    cout << ans << endl;

    return 0;
}
