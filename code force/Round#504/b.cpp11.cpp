#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n,k;



int main()
{
    cin>>n>>k;

    if(n+1>=k)
    {
        if(k%2==0)
        {
            cout << k/2-1 << endl;
            return 0;
        }
        else
        {
            cout << (k-1)/2 << endl;
            return 0;
        }
    }
    else if(2*n-1-k >= 0)
    {
        cout << (2*n-1-k)/2+1 << endl;
        return 0;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }

    return 0;
}
