#include <bits/stdc++.h>
using namespace std;

using ii=pair<int,int>;
int N;
int r[700][700], dp[700][700];
ii qry[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    int a, b;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b;
        qry[i] = {a,b};
        r[a][b]++;
    }

    dp[0][0] = r[0][0];

    for(int i=1;i<700;i++)
    {
        dp[0][i]=dp[0][i-1]+r[0][i];
        dp[i][0]=dp[i-1][0]+r[i][0];
    }

    for(int i=1;i<700;i++)
    {
        for(int j=1;j<700;j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + r[i][j];
        }
    }


    for(int i=0;i<N;i++)
    {
        int hi=1, lo=N;
        hi=hi+dp[699][699]-dp[699][qry[i].second]-dp[qry[i].first][699]+dp[qry[i].first][qry[i].second];

        if(qry[i].first != 0 && qry[i].second != 0) lo=lo-dp[qry[i].first-1][qry[i].second-1];
        lo = lo- r[0][qry[i].second] * (qry[i].first==650) - r[qry[i].first][0] * (qry[i].second==650);

        cout << hi << " " << lo << '\n';
    }

    return 0;
}
