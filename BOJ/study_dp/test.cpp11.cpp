#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
double dp[30000][31][50], p[31]={100, 100, 100, 90, 80, 70, 60, 50, 45, 45, 45, 45, 45, 40, 40, 40, 40, 40, 35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 30, 25};
int d=2;

int main()
{
    cin>>n>>m>>b;

    dp[0][m][0]=1.0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(j==b)
            {
                for(int k=0;k<50;k++) dp[i+1][j][k]+=dp[i][j][k];
                continue;
            }

            for(int k=0;k<50;k++) dp[i+1][min(j+1, 30)][0]+=((min(p[j]+d*k, 100.0))/100)*dp[i][j][k];
            for(int k=0;k<50;k++)
            {
                if(j==0 || j==10 || j==20 || j==30) dp[i+1][j][min(50, k+1)]+=((max(100-p[j]-d*k, 0.0))/100)*dp[i][j][k];
                else dp[i+1][j][min(50, k+1)]+=((max(100-p[j]-d*k, 0.0))/100)*dp[i][j][k];
            }
        }
    }

    double ret=0;
    for(int i=0;i<50;i++) ret+=dp[n][a][i];

    double ret2=0;
    for(int i=b;i<=30;i++)
    {
        for(int j=0;j<50;j++) ret2+=dp[n][i][j];
    }

    cout << "목표 강화 수치 이상 : " << ret2*100 << endl;

    return 0;
}
