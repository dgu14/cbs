#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using V = vector<T>;

int n;
V<ll> a,b;
V<ll> abSimple, atob, btoa, complete;

void precalc()
{
    abSimple[n-1] = a[n-1]+b[n-1];
    for(int i=n-1;i>=1;i--) abSimple[i-1]=abSimple[i]+a[i-1]+b[i-1];

    ll aStartSum = 0;
    for(int i=0;i<n;i++)
    {
        aStartSum += a[i] * i;
    }

    for(int i=0;i<n;i++)
    {
        aStartSum += b[n-1-i] * (i+n);
    }


    ll bStartSum = 0;
    for(int i=0;i<n;i++)
    {
        bStartSum += b[i] * i;
    }

    for(int i=0;i<n;i++)
    {
        bStartSum += a[n-1-i] * (i+n);
    }


    atob[0] = aStartSum;
    btoa[0] = bStartSum;

    for(int i=1;i<n;i++)
    {
        atob[i] = atob[i-1]-abSimple[i]-b[i-1]*(2*(n-i+1)-1);
        btoa[i] = btoa[i-1]-abSimple[i]-a[i-1]*(2*(n-i+1)-1);
    }

    complete[0] = b[0];

    for(int i=1;i<n;i++)
    {
        if(i%2==0) complete[i] = complete[i-1] + a[i]*(2*i) + b[i]*(2*i+1);
        else complete[i] = complete[i-1] + a[i]*(2*i+1)+b[i]*(2*i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a=V<ll>(n); b=V<ll>(n);
    abSimple=V<ll>(n,0);
    atob=V<ll>(n,0);
    btoa=V<ll>(n,0);
    complete=V<ll>(n,0);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    precalc();

    ll max_v = atob[0];

    for(int i=0;i<n-1;i++)
    {
        ll t = complete[i];
        if(i%2==0)
        {
            t += btoa[i+1] + abSimple[i+1]*(2*(i+1));
        }
        else
        {
            t += atob[i+1] + abSimple[i+1]*(2*(i+1));
        }

        max_v = max(max_v, t);
    }


    cout << max_v << endl;
    return 0;
}
