#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
int n;
V<int> x, y;
int main()
{
    cin >> n;
    x=V<int>(n), y =V<int>(n);

    int sx = 0, sy=0;
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
        sx+=x[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> y[i];
        sy+=y[i];
    }

    cout << (sx >= sy?"Yes":"No") << endl;

    return 0;
}
