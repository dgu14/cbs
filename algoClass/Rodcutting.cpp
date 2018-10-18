/// 2014004193_최범석_508
#include <iostream>
#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n) for(int i=(int)n;i>0;i--)
#define INF         1000000007
using namespace std;

int n, p[105], dp[105];
void printAll()
{
    cout << dp[n] << '\n';
    int cn=0,c[105], cl=n, cll=n-1;

    while(cl>0)
    {
        while(dp[cl]!=dp[cll]+p[cl-cll]) cll--;
        c[cn++]=cl-cll;
        cl=cll;cll--;
    }

    forn(i,cn)
    {
        cout << c[i] << ' ';
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n;
    forn1(i,n) cin>>p[i];

    forn1(i,n)
    {
        forn(j,i)
        {
            dp[i]=max(dp[i], dp[j]+p[i-j]);
        }
    }

    printAll();
    return 0;
}
