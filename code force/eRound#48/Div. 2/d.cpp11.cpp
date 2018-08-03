#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
int n,m,aa,bb;
V<int> a,b;
V<V<int>> mat;
int main()
{
    cin>>n>>m;
    a=V<int>(n); b=V<int>(m);
    mat=V<V<int>> (n, V<int>(m, 0));
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        aa^=a[i];
    }

    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        bb^=b[i];
    }

    if(aa!=bb)
    {
        cout << "NO" << endl;
        return 0;
    }

    mat[0][0] = aa^a[0]^b[0];
    for(int i=1;i<m;i++)
    {
        mat[0][i] = b[i];
    }

    for(int i=1;i<n;i++)
    {
        mat[i][0] = a[i];
    }

    cout << "YES" << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
