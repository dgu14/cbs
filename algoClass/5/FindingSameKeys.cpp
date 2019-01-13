// 2014004193_choibeomseok_508
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int n,m,a[100005],b,ret;
int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    for(int i=0;i<m;i++)
    {
        cin>>b;
        if(binary_search(a, a+n, b)) ret++;
    }

    cout<<ret<<endl;

    return 0;
}
