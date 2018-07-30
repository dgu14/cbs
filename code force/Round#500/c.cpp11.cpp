#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ll = long long;
int n;
V<ll> a;

int main()
{
    cin >> n;
    n = 2*n;
    a=V<ll>(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll minSquare = 1e18;

    ll x1,x2,y1,y2;
    for(int i=1;i<n/2;i++)
    {
        x1=a[i];
        x2=a[i+n/2-1];
        y1=a[0];
        y2=a[n-1];

        minSquare = min(minSquare, (x2-x1)*(y2-y1));
    }


    minSquare = min(minSquare, (a[n/2-1]-a[0])*(a[n-1]-a[n/2]));
    cout << minSquare << endl;

    return 0;
}
