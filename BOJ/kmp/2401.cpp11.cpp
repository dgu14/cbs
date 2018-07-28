#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int, int>;

int n;
string L;
V<string> l;
bool w[100001][501];
int dp[100001];


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

    for(int i=0;i<(int)L.size();i++)
    {
        while(matched != 0 && L[i] != l[itr][matched]) matched = p[matched-1];

        if(l[itr][matched] == L[i])
        {
            matched ++;

            if(matched == (int)l[itr].size())
            {
                w[i][itr] = true;
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
    l = V<string>(n);
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) kmp(i);
    for(int i=0;i<(int)L.size();i++)
    {
        dp[i] = dp[i-1];
        for(int j=0;j<n;j++)
        {
            if(w[i][j]) dp[i] = max(dp[i], dp[i-(int)l[j].size()]+(int)l[j].size());
        }
    }

    cout << dp[L.size()-1] << endl;

    return 0;
}
