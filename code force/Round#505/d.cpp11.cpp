#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;
template<class T> using V=vector<T>;

ll n,a[1000], GCD[1000][1000];
int dp[1000][1000][2];

ll gcd(ll a, ll b)
{
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}

void precalc()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            GCD[i][j]=gcd(a[i],a[j]);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    precalc();


    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp[1][1][0]=0;
            dp[1][1][1]=GCD[1][2]>1;
        }
        else if(i==n)
        {
            dp[n][n][0]=GCD[n][n-1]>1;
            dp[n][n][1]=0;
        }
        else
        {
            dp[i][i][0]=GCD[i][i-1]>1;
            dp[i][i][1]=GCD[i][i+1]>1;
        }
    }


    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j+i-1>n) continue;
            for(int k=j;k<=j+i-1;k++)
            {
                if(k==j)
                {
                    if(dp[k+1][j+i-1][0]==1)
                    {
                        if(GCD[j-1][k]>1) dp[j][j+i-1][0]|=1;
                        if(GCD[j+i][k]>1) dp[j][j+i-1][1]|=1;
                    }
                }
                else if(k==j+i-1)
                {
                    if(dp[j][k-1][1]==1)
                    {
                        if(GCD[j-1][k]>1) dp[j][j+i-1][0]|=1;
                        if(GCD[j+i][k]>1) dp[j][j+i-1][1]|=1;
                    }
                }
                else
                {
                    if(dp[j][k-1][1]==1&&dp[k+1][j+i-1][0]==1)
                    {
                        if(GCD[j-1][k]>1) dp[j][j+i-1][0]|=1;
                        if(GCD[j+i][k]>1) dp[j][j+i-1][1]|=1;
                    }
                }

            }
        }
    }


    int test=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            test |= (dp[2][n][0]==1);
        }
        else if(i==n)
        {
            test |= (dp[1][n-1][1]==1);
        }
        else
        {
            test |= (dp[1][i-1][1]==1&&dp[i+1][n][0]==1);
        }
    }

    cout << (test==1?"Yes":"No") << endl;


    return 0;
}

