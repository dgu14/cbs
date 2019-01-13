// 2014004193_choibeomseok_508
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

string a,b;
int dp[1000][1000];
int main()
{
    cin>>a>>b;
    if(a.compare(b)<0) swap(a,b);

    int as=a.size(), bs=b.size();
    for(int i=0;i<=as;i++)
    {
        for(int j=0;j<=bs;j++)
        {
            if(a[i]==b[j]) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            dp[i][j+1]=max(dp[i][j+1], dp[i][j]);
        }
    }

    string ret;
    int p,q;

    p=as, q=bs;

    while(!(p==0 || q==0))
    {
        if(dp[p][q]==dp[p-1][q]) p--;
        else if(dp[p][q]==dp[p][q-1]) q--;
        else
        {
            p--; q--; ret+=a[p];
        }
    }

    reverse(ret.begin(), ret.end());
    cout << ret << endl;

    return 0;
}
