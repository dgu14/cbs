#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<int,int>;
template <class T> using V=vector<T>;
int n,h,a,b,q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>h>>a>>b>>q;

    int i,j,k,r;
    while(q--)
    {
        cin>>i>>j>>k>>r;

        int ret=0;

        if(i==k)
        {
            cout << abs(j-r) << '\n';
            continue;
        }

        if(j>b) ret+=j-b, j=b;
        if(j<a) ret+=a-j, j=a;

        if(r>b) ret+=r-b, r=b;
        if(r<a) ret+=a-r, r=a;

        ret += abs(i-k) + abs(j-r);
        cout << ret << '\n';
    }

    return 0;
}
