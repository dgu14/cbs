#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;

    int pos = -1, m=999999999;
    for(int i=1;i<n;i++)
    {
        int ret = 0;
        ret += n/i;
        if(n%i != 0) ret += 1;

        ret += i;

        if(ret < m)
        {
            pos = i;
            m = ret;
        }
    }

    vector<vector<int>> a;

    for(int i=0;i<n;i++)
    {
        if(a.size() == 0 || a[a.size()-1].size() == pos)
        {
            a.push_back(vector<int> (1, i+1));
        }
        else if(a.size() && a[a.size()-1].size() != pos)
        {
            a[a.size()-1].push_back(i+1);
        }
    }

    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
