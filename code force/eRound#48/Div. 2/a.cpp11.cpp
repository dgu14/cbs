#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using V = vector<T>;
using ii = pair<int,int>;

ll n,m;
V<ll> arr;

int main()
{
    cin>>n>>m;
    arr=V<ll>(n);
    for(int i=0;i<n;i++) cin >> arr[i];


    ll s=0;
    for(int i=0;i<n;i++)
    {
        ll os = s;
        s+=arr[i];

        cout << s/m - os/m << endl;
    }

    return 0;
}
