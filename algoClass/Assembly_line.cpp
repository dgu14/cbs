/// 2014004193_최범석_508
#include <iostream>
#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n) for(int i=(int)n;i>0;i--)
#define INF         1000000007
using namespace std;

int N,e1,e2,x1,x2, a1[105], a2[105], t1[105], t2[105], dp1[105], dp2[105];

void printAll()
{
    int c, l[105];
    if(dp2[N]+x2>dp1[N]+x1) c=dp1[N]+x1, l[N]=1;
    else c=dp2[N]+x2, l[N]=2;

    cout << c << '\n';
    if(l[N]==1) c-=x1; else c-=x2;
    rforn1(i,N)
    {
        if(i==N) continue;
        if(l[i+1]==1)
        {
            if(dp1[i]+a1[i+1]==c) c-=a1[i+1], l[i]=1;
            else if(dp2[i]+a1[i+1]+t2[i]==c) c-=a1[i+1]+t2[i], l[i]=2;
        }
        else
        {
            if(dp2[i]+a2[i+1]==c) c-=a2[i+1], l[i]=2;
            else if(dp1[i]+a2[i+1]+t1[i]==c) c-=a2[i+1]+t1[i], l[i]=1;
        }
    }

    forn1(i,N)
    {
        cout << l[i] << ' ' << i << '\n';
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin>>N>>e1>>e2>>x1>>x2;

    forn1(i,N) cin>>a1[i];
    forn1(i,N) cin>>a2[i];
    forn1(i,N-1) cin>>t1[i];
    forn1(i,N-1) cin>>t2[i];

    dp1[1]=e1+a1[1]; dp2[1]=e2+a2[1];
    forn1(i,N)
    {
        if(i==1) continue;
        dp1[i]=min(dp1[i-1], dp2[i-1]+t2[i-1])+a1[i];
        dp2[i]=min(dp2[i-1], dp1[i-1]+t1[i-1])+a2[i];
    }

    printAll();
    return 0;
}
