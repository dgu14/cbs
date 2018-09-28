// 2014004193_ÃÖ¹ü¼®_508
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n,m,k,a[100005], s[100005], t;
ii qry[100005];

int main()
{
    scanf("%d%d%d", &n,&m,&k);
    for(int i=0;i<k;i++) scanf("%d%d",&qry[i].first,&qry[i].second);
    for(int i=0;i<n;i++) scanf("%d",&t), a[t]++;

    for(int i=1;i<=100000;i++) s[i]=s[i-1]+a[i];

    for(int i=0;i<k;i++)
    {
        printf("%d\n", s[qry[i].second]-s[qry[i].first-1]);
    }

    return 0;
}

