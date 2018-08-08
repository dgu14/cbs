#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,k, arr[1000001], bucket[1005],sn;

ll query(ll l, ll r)
{
    ll ret = 0;
    ll bl = l/sn;
    ll br = r/sn;

    for(ll i=bl*sn;i<l;i++)
    {
        ret -= arr[i];
    }

    for(ll i=bl;i<br;i++)
    {
        ret += bucket[i];
    }

    for(ll i=br*sn;i<=r;i++)
    {
        ret += arr[i];
    }

    return ret;
}

int update(ll x, ll b)
{
    bucket[x/sn] -= arr[x];
    bucket[x/sn] += b;
    arr[x] = b;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    sn=sqrt(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        bucket[i/sn]+=arr[i];
    }

    ll a,b,c;
    for(int i=0;i<m+k;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            update(b-1, c);
        }
        else
        {
            if(b>c) swap(b,c);
            cout << query(b-1,c-1) << '\n';
        }
    }

    return 0;
}
