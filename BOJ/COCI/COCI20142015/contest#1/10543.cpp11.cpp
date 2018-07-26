#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ll sum(ll i, ll k)
{
    return i*(i+1)/2 * k;
}

ll nNoise(ll n, ll k)
{
    ll ret = sum(n/(k+1), k+1);
    ret += (n%(k+1)) * (n/(k+1)+1);

    return ret;
}

ll dp[101][505];
int a[101];

int main()
{
    int n,m,k, t;
    cin >> n >> m >> k;

    for(int i=0;i<101;i++)
    {
        for(int j=0;j<505;j++)
        {
            dp[i][j] = 1e18;
        }
    }


    for(int i=0;i<n;i++)
    {
        cin >> t;
        a[t-1] ++;
    }

    for(int i=0;i<=k;i++)
    {
        dp[0][i] = nNoise(a[0], i);
    }

    for(int i=1;i<m;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int r=0;r<=j;r++)
            {
                dp[i][j] = min(dp[i-1][r] + nNoise(a[i], j-r), dp[i][j]);
            }
        }
    }

    ll ret=1e18;
    for(int i=0;i<=k;i++)
    {
        ret = min(ret, dp[m-1][i]);
    }

    cout << ret << endl;

    return 0;
}
