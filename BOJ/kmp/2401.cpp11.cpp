#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int, int>;

int n;
string L;
V<string> l;
V<short> w[100005];
int dp[100005];


void kmp(int itr)
{
    int s = l[itr].size();
    V<int> p(s, 0);

    int matched = 0;
    for(int i=1;i<s;i++)
    {
        while(matched != 0 && l[itr][i] != l[itr][matched]) matched = p[matched-1];

        if(l[itr][i] == l[itr][matched]) matched++;
        p[i] = matched;
    }


    matched = 0;

    for(int i=0;i<L.size();i++)
    {
        while(matched != 0 && L[i] != l[itr][matched]) matched = p[matched-1];

        if(l[itr][matched] == L[i])
        {
            matched ++;

            if(matched == l[itr].size())
            {
                w[i].push_back((short)itr);
                matched = p[matched-1];
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> n;
    l = V<string> (n);
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) kmp(i);

    for(int i=0;i<(int)L.size();i++)
    {
        dp[i] = dp[i-1];
        for(int j=0;j<(int)w[i].size();j++)
        {
            int k = l[w[i][j]].size();
            dp[i] = max(dp[i], dp[i-k]+k);
        }
    }

    cout << dp[L.size()-1] << endl;

    return 0;
}
