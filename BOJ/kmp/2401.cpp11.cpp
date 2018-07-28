#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int, int>;

int n;
string L;
V<string> l;

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
                dp[i] = matched;
                matched = p[matched-1];
            }
        }
    }
}


int totSize;
V<int> dp2, pos, leng;


int lowerOneNotOverlaped(int i)
{
    return lower_bound(pos.begin(), pos.begin()+i, pos[i] - leng[i] + 1)-pos.begin()-1;
}

int main()
{
    cin >> L >> n;
    l = V<string> (n);
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) kmp(i);

    for(int i=0;i<100000;i++)
    {
        if(dp[i])
        {
            pos.push_back(i);
            leng.push_back(dp[i]);
        }
    }

    totSize = pos.size();
    dp2 = V<int>(totSize, 0);

    for(int i=0;i<totSize;i++)
    {
        dp2[i] = leng[i];

        int s=lowerOneNotOverlaped(i);
        if(s==-1) continue;
        int t=lowerOneNotOverlaped(s);

        for(int j=t+1;j<=s;j++)
        {
            dp2[i] = max(dp2[i], dp2[j] + leng[i]);
        }
    }

    int max_t=0;
    for(int i=0;i<dp2.size();i++)
    {
        max_t = max(max_t, dp2[i]);
    }

    cout << max_t << endl;

    return 0;
}
