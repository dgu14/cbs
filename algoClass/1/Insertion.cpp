// 2014004193_최범석
#include <iostream>
using namespace std;
typedef long long ll;


ll n, a[100000];
void sort()
{
    for(int i=2;i<=n;i++)
    {
        int j=i-1, t=a[i];
        while(j>=1 && a[j]<t)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=t;
    }
}


int main()
{
    cin.tie(0); cout.tie(0);
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i]; sort(); for(int i=1;i<=n;i++) cout<<a[i]<<'\n';
    return 0;
}
