#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;
template<class T> using V=vector<T>;

int n;
string str;
int cnt[26];
int main()
{
    cin>>n>>str;

    for(int i=0;i<n;i++)
    {
        cnt[str[i]-'a']++;
    }

    bool pos=false;
    for(int i=0;i<26;i++)
    {
        if(cnt[i] >= 2) pos=true;
    }

    if(pos || n==1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
