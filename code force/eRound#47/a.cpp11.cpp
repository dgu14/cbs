#include <bits/stdc++.h>
using namespace std;

int n,m;
int c[1005], a[1005];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<m;i++) cin>>a[i];

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]<=a[j])
        {
            j++;
        }
    }

    cout << j << endl;

    return 0;
}
