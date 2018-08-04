#include <bits/stdc++.h>
using namespace std;

int n,mink, arr[505];
int m;
int main()
{
    cin>>n>>mink;
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
        m += arr[i];
    }

    double ret = 1e18;

    for(int k=mink;k<=n;k++)
    for(int i=0;i<n;i++)
    {
        if(i+k-1 >= n) break;
        double av = 0;

        for(int j=i;j<i+k;j++)
        {
            av += arr[j];
        }

        av = av/k;


        double sigma = 0;
        for(int j=i;j<i+k;j++)
        {
            sigma += (arr[j]-av) * (arr[j]-av);
        }

        sigma = sigma/k;
        ret = min(ret, sqrt(sigma));
    }

    printf("%.8f\n", ret);

    return 0;
}
