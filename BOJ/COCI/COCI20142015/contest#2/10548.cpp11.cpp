#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ll n,m, a[1001][1001], p[1001][1001], dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            p[i][j] = 1;

            if(i>=1 && a[i][j] == a[i-1][j])
            {
                p[i][j] = p[i-1][j]+1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        stack<ii> stk;
        ll srt=0;
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                stk.push({p[i][j], j});
                dp[i][j] = p[i][j];
                continue;
            }

            if(a[i][j] != a[i][j-1])
            {
                while(stk.size()) stk.pop();

                stk.push({p[i][j], j});
                dp[i][j] = p[i][j];
                srt = j;
            }
            else
            {
                while(stk.size() && stk.top().first >= p[i][j])
                {
                    stk.pop();
                }

                if(stk.size())
                {
                    dp[i][j] += dp[i][stk.top().second];
                    dp[i][j] += (j-stk.top().second) * p[i][j];
                }
                else
                {
                    dp[i][j] += (j-srt+1) * p[i][j];
                }

                stk.push({p[i][j], j});
            }
        }
    }

    ll ret = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ret += dp[i][j];
        }
    }

    cout << ret << endl;

    return 0;
}
