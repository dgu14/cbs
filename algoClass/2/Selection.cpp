// 2014004193_최범석
#include <iostream>
using namespace std;
typedef long long ll;
ll const INF=(ll) 1e18;
ll n, m, a[100000];

int min_elem(int l, int r)
{
    int po=-1;
    ll mv=INF;
    for(int i=l;i<=r;i++)
    {
        if(mv>a[i])
        {
            mv=a[i];
            po=i;
        }
    }

    return po;
}

void sort()
{
    int s=m, t=1;

    while(s--)
    {
        int k=min_elem(t, n);
        swap(a[t], a[k]);

        t++;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]; sort();
    for(int i=1;i<=n;i++) cout<<a[i]<<'\n';

    return 0;
}
