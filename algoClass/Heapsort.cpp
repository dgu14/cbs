// 2014004193_ÃÖ¹ü¼®_508
#include <iostream>
using namespace std;
typedef long long ll;
ll const INF=(ll) 1e18;
ll n, m, a[100000];

void heapify(int k)
{
    if(2*k>n) return;

    if(2*k+1>n || a[2*k]>=a[2*k+1])
    {
        if(a[2*k]>a[k])
        {
            swap(a[2*k], a[k]);
            heapify(2*k);
        }
    }
    else
    {
        if(a[2*k+1]>a[k])
        {
            swap(a[2*k+1], a[k]);
            heapify(2*k+1);
        }
    }
}

void build_max_heap()
{
    for(int i=n;i>=1;i--) heapify(i);
}

ll extract_max()
{
    swap(a[1], a[n]); n--;
    heapify(1);

    return a[n+1];
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    build_max_heap();

    for(int i=1;i<=m;i++)
    {
        cout << extract_max() << ' ';
    }
    cout << '\n';

    for(int i=1;i<=n;i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}

