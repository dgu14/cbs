#include <bits/stdc++.h>
using namespace std;

using ii=pair<int,int>;

int gcd(int a, int b)
{
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}

int n,m, k;
ii edges[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(gcd(i, j) == 1)
            {
                edges[k++]={i,j};

                if(k==m) break;
            }
        }

        if(k==m) break;
    }

    if(k!=m || k < n-1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << "Possible" << endl;

        for(int i=0;i<k;i++)
        {
            cout << edges[i].first << ' ' << edges[i].second << '\n';
        }
    }

    return 0;
}
