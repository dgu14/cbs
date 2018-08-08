#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
string a, b;
int main()
{
    cin>>n>>a>>b;

    ll zeros=0,ones=0;
    ll twoOnes=0, mixed=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] =='0')zeros++;
        else ones++;

        if(a[i] == '1' && b[i] == '1') twoOnes++;
        else if(a[i] == '0' && b[i] =='1') mixed++;
    }

    cout << zeros*ones - twoOnes * mixed << endl;

    return 0;
}
