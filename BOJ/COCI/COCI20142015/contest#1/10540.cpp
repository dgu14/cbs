#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1=105,y1=105,x2=-5,y2=-5,n,a,b;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> a >> b;

        x1 = min(x1, a);
        y1 = min(y1, b);

        x2 = max(x2, a);
        y2 = max(y2, b);
    }

    int r=max(x2-x1, y2-y1);
    cout << r*r << endl;

    return 0;
}
