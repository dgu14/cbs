#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
int n,x;
V<int> a;

int main()
{
    cin >> n >> x;
    a=V<int>(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());


    int ret = -1;
    for(int i=0;i<n;i++)
    {
        if(binary_search(a.begin(), a.begin()+i, a[i]) || binary_search(a.begin()+i+1, a.end(), a[i]))
        {
            ret=0;
            break;
        }
    }

    if(ret == -1)
    {
        for(int i=0;i<n;i++)
        {
            if(binary_search(a.begin(), a.begin()+i, a[i]&x) || binary_search(a.begin()+i+1, a.end(), a[i]&x))
            {
                ret=1;
                break;
            }
        }
    }


    if(ret == -1)
    {
        for(int i=0;i<n;i++) a[i] = a[i]&x;
        sort(a.begin(), a.end());

        for(int i=0;i<n;i++)
        {
            if(binary_search(a.begin(), a.begin()+i, a[i]) || binary_search(a.begin()+i+1, a.end(), a[i]))
            {
                ret=2;
                break;
            }
        }
    }

    cout << ret << endl;
    return 0;
}
