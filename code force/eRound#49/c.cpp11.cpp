#include <bits/stdc++.h>
using namespace std;

int arr[2000000];
int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)
    {
        int n;

        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &arr[i]);

        sort(arr, arr+n);

        vector<int> f;
        for(int i=0;i<n-1;i++)
        {
            if(i!=n-1&&arr[i]==arr[i+1])
            {
                f.push_back(arr[i]);
                i++;
            }
        }

        double x,y,v=2e9;
        int min_p=-1;

        for(int i=0;i<f.size()-1;i++)
        {
            x=f[i], y=f[i+1];
            if(v> (x+y)*(x+y)/(x*y))
            {
                v=(x+y)*(x+y)/(x*y);
                min_p=i;
            }
        }

        printf("%d %d %d %d\n", f[min_p], f[min_p], f[min_p+1], f[min_p+1]);
    }

    return 0;
}
