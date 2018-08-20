#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;
template<class T> using V=vector<T>;

ll n;
V<ll> lists;
V<ii> ls;

ll gcd(ll a,ll b)
{
    if(b>a) swap(a,b);

    if(b==0) return a;
    return gcd(b, a%b);
}

ll lgcd(ll a)
{

    for(ll i=2;i*i<=a;i++)
    {
        if(a%i==0) return i;
    }

    return a;
}

int main()
{
    cin>>n;
    ll a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        lists.push_back(a*b);
        ls.push_back({a,b});
    }

    ll g=lists[0];

    for(int i=1;i<n;i++)
    {
        g=gcd(g, lists[i]);
    }


    ll ret1=g;
    ll ret2=g;

    ret1=gcd(g,ls[0].first);
    ret2=gcd(g,ls[0].second);

    if(ret1!=1)
    {
        cout << lgcd(ret1) << endl;
    }
    else if(ret2!= 1) cout << lgcd(ret2) << endl;
    else cout << -1 << endl;


    return 0;
}
