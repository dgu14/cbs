// 2014004193_ÃÖ¹ü¼®_508
#include <iostream>
using namespace std;
typedef long long ll;


ll n, a[200000], ct[200000];

void merge(int l, int r, int b, int t)
{
    int p=l, q=b, c=0;

    while(p<=r && q<=t)
    {
        if(a[p]>a[q]) ct[c++]=a[p], p++;
        else ct[c++]=a[q], q++;
    }

    while(p<=r) ct[c++]=a[p], p++;
    while(q<=t) ct[c++]=a[q], q++;
    for(int i=0;i<c;i++) a[l+i]=ct[i];
}

void sort(int lo, int hi)
{
    if(lo>=hi) return;
    int mid=(lo+hi)>>1;
    sort(lo, mid); sort(mid+1, hi); merge(lo, mid, mid+1, hi);
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i]; sort(1, n); for(int i=1;i<=n;i++) cout<<a[i]<<'\n';
    return 0;
}

