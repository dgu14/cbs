#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n; string str;
        cin>>n>>str;


        bool test=true;
        for(int i=0;i<n/2;i++)
        {
            if(abs(str[i]-str[n-1-i])==2 || abs(str[i]-str[n-1-i])==0) continue;
            else
            {
                test=false;
                break;
            }
        }

        if(test) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
