#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using V = vector<T>;

ll scarePos(ll k, ll w)
{
    ll a,b;
    if(k%2 ==0)
    {
        a = (k/2)%w;
        b = (k-1)%w;
    }
    else
    {
        a = ((k-1)/2)%w;
        b = k%w;
    }

    if((a*b)%w == 0) return 0;
    return w-(a*b)%w;
}

V<int> dp[26];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    ll n, k, a;
    char c;
    cin >> n >> str >> k;

    ll w = str.size();

    for(int i=1;i<=w;i++)
    {
        dp[str[i-1]-'A'].push_back(i);
    }

    while(k--)
    {
        cin >> a >> c;

        ll r = scarePos(a, w), gatsu = 0;

        if(a-r<0) gatsu += upper_bound(dp[c-'A'].begin(), dp[c-'A'].end(), w-r+a) - lower_bound(dp[c-'A'].begin(), dp[c-'A'].end(), w-r+1);
        else if(a-r == 0) gatsu += dp[c-'A'].end() - lower_bound(dp[c-'A'].begin(), dp[c-'A'].end(), w-r+1);
        else if(a-r>0)
        {
            gatsu += dp[c-'A'].end() - lower_bound(dp[c-'A'].begin(), dp[c-'A'].end(), w-r+1);
            gatsu += dp[c-'A'].size() * ((a-r)/w);
            gatsu += upper_bound(dp[c-'A'].begin(), dp[c-'A'].end(), (a-r)%w) - dp[c-'A'].begin();
        }

        cout << gatsu << '\n';
    }

    return 0;
}
