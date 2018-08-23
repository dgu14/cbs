#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
int const MAX_N=1024*1024;
int n, m, a[MAX_N][2], s[2*MAX_N], dn[3*MAX_N], lo=0, hi, ret=-1, mid, an, bn;
V<int> adj[3*MAX_N];

void dfs(int srt, int d)
{
    if(srt<n) an++; else bn++; dn[srt]=1;
    if(srt>=n) for(int to:adj[srt]) { if(!dn[to]) dfs(to, d); }
    else for(int to=0;to<2;to++) { if(a[srt][to]>d) break; if(!dn[a[srt][to]+n]) { dfs(a[srt][to]+n, d); }}
}

bool chk(int d)
{
    memset(dn, 0, sizeof(dn));
    for(int i=0;i<n;i++) if(!dn[i]){ an=0; bn=0; dfs(i, d); if(an>bn) return false; }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){ scanf("%d%d", &a[i][0], &a[i][1]); s[m++]=a[i][0]; s[m++]=a[i][1]; lo=max(lo, a[i][0]); }
    //for(int i=0;i<n;i++){ a[i][0]=i; a[i][1]=1e9-i; s[m++]=a[i][0]; s[m++]=a[i][1]; lo=max(lo, a[i][0]); }
    sort(s, s+m); m=unique(s, s+m)-s; hi=m;

    for(int i=0;i<n;i++){ a[i][0]=lower_bound(s, s+m, a[i][0])-s; a[i][1]=lower_bound(s, s+m, a[i][1])-s;
         adj[a[i][0]+n].push_back(i); adj[a[i][1]+n].push_back(i);}
    lo=lower_bound(s, s+m, lo)-s;

    while(lo<=hi){ mid=(lo+hi)>>1; if(chk(mid)){ ret=mid; hi=mid-1; } else lo=mid+1; }
    if(ret!=-1) printf("%d\n", s[ret]); else printf("-1\n");
    return 0;
}
