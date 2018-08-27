#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n,m,q,w[20],K[500005], sum[5000], mx[5000], my[5000][105];
ll S[500005], Q[500005];
ll const mask = (1<<12)-1;

ll toBin(ll ten)
{
    ll f=n, r=0, b=1;
    while(f--)
    {
        r+=(ten%10)*b;
        ten/=10;
        b*=2;
    }

    return r;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<m;i++) cin>>S[i], S[i]=toBin(S[i]), mx[S[i]]++;
    for(int i=0;i<q;i++) cin>>Q[i]>>K[i], Q[i]=toBin(Q[i]);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5000;j++)
        {
            if(!(j&(1<<i))) sum[j]+=w[n-1-i];
        }
    }

    for(int i=0;i<5000;i++)
    {
        for(int j=0;j<5000;j++)
        {
            my[i][min(101ll, sum[(i^j)&mask])] += mx[j];
        }
    }

    for(int i=0;i<q;i++)
    {
        int ret=0;
        for(int j=0;j<=K[i];j++)
        {
            ret+= my[Q[i]][j];
        }

        cout << ret << '\n';
    }

    return 0;
}
