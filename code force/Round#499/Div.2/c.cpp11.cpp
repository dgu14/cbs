#include <bits/stdc++.h>
using namespace std;

int n,m,a[1005],b[1005];

bool canfly(double fuel, bool test)
{
    double tot = fuel+m;

    for(int i=0;i<n-1;i++)
    {
        fuel -= tot/a[i];
        tot -= tot/a[i];
        if(fuel < 0) return false;

        fuel -= tot/b[i+1];
        tot -= tot/b[i+1];

        if(fuel < 0) return false;
    }

    fuel -= tot/a[n-1];
    tot -= tot/a[n-1];
    if(fuel < 0) return false;

    fuel -= tot/b[0];
    tot -= tot/b[0];
    if(fuel < 0) return false;

    return true;
}

int main()
{
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    double left = 0, right = 1e9, ret = -1;

    for(int i=0;i<1000;i++)
    {
        double mid = (left+right)/2;

        if(canfly(mid, false))
        {
            ret = mid;
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout << fixed;
    cout.precision(7); // 병신 이거 안해줘서 틀리네 ㅎ
    cout << ret << endl;


    return 0;
}
