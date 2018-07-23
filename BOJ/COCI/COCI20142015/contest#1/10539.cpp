#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i] *= (i+1);
    }

    b[0] = a[0];
    for(int i=1;i<n;i++)
    {
        b[i] = a[i]-a[i-1];
    }

    for(int i=0;i<n;i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;



    return 0;
}
