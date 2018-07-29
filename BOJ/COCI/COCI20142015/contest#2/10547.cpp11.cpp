#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int, int>;
int n,k;
V<int> v;
V<ii> t;

int main()
{
    cin >> n >> k;
    v=V<int>(n);t=V<ii>(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        t[i] = {v[i], i};
    }

    sort(t.begin(), t.end());

    for(int i=0;i<n;i++)
    {
        v[t[i].second] = i/k;
    }


    V<int> dp;
    for(int i=0;i<n;i++)
    {
        int k=upper_bound(dp.begin(), dp.end(), v[i])-dp.begin();
        if(k==dp.size()) dp.push_back(v[i]);
        else dp[k] = v[i];
    }

    cout << n-dp.size() << endl;

    return 0;
}
