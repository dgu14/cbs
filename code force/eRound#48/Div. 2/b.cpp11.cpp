#include <bits/stdc++.h>
using namespace std;

int n,m,q;
string a,b;

vector<int> kmp()
{
    vector<int> ret;
    vector<int> p(m,0);
    int matched = 0;
    for(int i=1;i<m;i++)
    {
        while(matched != 0 && b[i] != b[matched]) matched = p[matched-1];

        if(b[i] == b[matched])
        {
            matched++;
            p[i] = matched;
        }
    }

    matched =0 ;
    for(int i=0;i<n;i++)
    {
        while(matched != 0 && a[i] != b[matched]) matched = p[matched-1];

        if(a[i] == b[matched])
        {
            matched++;

            if(matched == m)
            {
                ret.push_back(i-m+1);
                matched = p[matched-1];
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    cin >> a >> b;

    vector<int> idx = kmp();
    int s,t;
    for(int i=0;i<q;i++)
    {
        cin >> s >> t;
        s--;t--;

        int from = lower_bound(idx.begin(), idx.end(), s)-idx.begin();
        int to = upper_bound(idx.begin(), idx.end(), t)-idx.begin();

        int ret = 0;
        for(int j=from;j<to;j++)
        {
            if(idx[j]+m-1 <= t)
            {
                ret++;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}

