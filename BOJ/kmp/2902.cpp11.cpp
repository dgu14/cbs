#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    string ans;
    ans+=str[0];

    for(int i=1;i<str.size();i++)
    {
        if(str[i] == '-')
        {
            ans+=str[i+1];
        }
    }

    cout << ans << endl;

    return 0;
}
