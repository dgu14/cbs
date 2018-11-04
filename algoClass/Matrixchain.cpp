/// 2014004193_ÃÖ¹ü¼®_508
#include <iostream>
#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n) for(int i=(int)n;i>0;i--)
#define INF         1000000007
using namespace std;

int n, p[105], dp[105][105], s[105][105];

void print_answer(int pl, int pr)
{
    if(pr==pl)
    {
        cout << pl+1 << ' ';
        return;
    }

    cout << "( ";
    print_answer(pl, s[pl][pr]);
    print_answer(s[pl][pr]+1, pr);
    cout << ") ";
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n+1) cin>>p[i];

    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
    }

    for(int l=2;l<=n;l++)
    {
        for(int j=0;j+l-1<n;j++)
        {
            dp[j][j+l-1]=INF;
            for(int k=j;k<j+l-1;k++)
            {
                if(dp[j][j+l-1]>dp[j][k]+dp[k+1][j+l-1]+p[j]*p[k+1]*p[j+l])
                {
                    s[j][j+l-1]=k;
                    dp[j][j+l-1]=dp[j][k]+dp[k+1][j+l-1]+p[j]*p[k+1]*p[j+l];
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
    print_answer(0, n-1);
    return 0;
}
