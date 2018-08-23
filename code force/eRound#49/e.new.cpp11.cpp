#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll const MOD=998244353;
ll n,k;


int dp[2][505][505], cnt[505], sm[505];

void add(int& a, int b)
{
    a += b;
    if(a >= MOD)
    {
        a-=MOD;
    }
}

int main()
{
    cin>>n>>k;


    dp[0][1][1]=1;
    for(int i=0;i<n-1;i++)
    {
        memset(dp[(i+1)%2], 0, sizeof(dp[(i+1)%2]));
        for(int j=1;j<=i+1;j++)
        {
            for(int r=1;r<=i+1;r++)
            {
                add(dp[(i+1)%2][j+1][max(j+1,r)], dp[i%2][j][r]);
                add(dp[(i+1)%2][1][r], dp[i%2][j][r]);
            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            add(cnt[i], dp[(n-1)%2][j][i]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        add(sm[i], sm[i-1]);
        add(sm[i], cnt[i]);
    }


    int ret=0;
    for(int i=1;i<=n;i++)
    {
        add(ret, (1ll * 2 * cnt[i] * sm[min(n,(k-1)/i)])%MOD);
    }

    cout << ret << endl;

    return 0;
}
