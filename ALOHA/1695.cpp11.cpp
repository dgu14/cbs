#include <bits/stdc++.h>
using namespace std;

int n, a[5005], dp[5005][5005];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    dp[0][0]=0;

       for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(a[i] == a[n+1-j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                }

                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
        }

    cout << n-max(dp[n+1][n], dp[n][n+1])<<endl;

    return 0;
}
