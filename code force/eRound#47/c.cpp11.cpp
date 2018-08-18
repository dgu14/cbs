#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;
ll n,m;
int main()
{
    cin>>n>>m;

    ll x,d,s=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>d;
        s=s+x*n;

        if(d>=0)
        {
            s+=d*n*(n-1)/2;
        }
        else
        {
            ll t=n/2;
            s+=2*d*t*(t+1)/2;
            if(n%2==0) s-= d * t;
        }
    }

    printf("%.8f\n", (double)s/n);

    return 0;
}
