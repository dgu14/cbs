#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n,q;

ll f(ll x,ll y)
{
    if((x+y)%2==0)
    {
        ll t=0;

        ll of=(x+1)/2,ef=x/2;
        t+=of*((n+1)/2) + ef*(n/2);

        if(x%2==0)
        {
            t-=n/2-(y+1)/2;
        }
        else t-= (n+1)/2-(y+1)/2;

        return t;
    }
    else
    {
        ll t=0;

        ll of=(x+1)/2,ef=x/2;
        t+=ef*((n+1)/2) + of*(n/2);

        if(x%2==0)
        {
            t-=(n+1)/2-(y+1)/2;
        }
        else t-= n/2-(y+1)/2;


        ll f=n*n/2;
        if(n%2!=0) f+=1;
        return t+;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;

    ll x,y;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        cout << f(x,y) << '\n';
    }

    return 0;
}
