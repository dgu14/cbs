#include <bits/stdc++.h>
using namespace std;

using ii=pair<int,int>;
int n;
vector<ii> sc;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
       int s=0, t;
       for(int j=0;j<4;j++)
       {
           cin >> t;
           s += t;
       }
       sc.push_back({s, i});
    }

    sort(sc.begin(), sc.end(), [](ii a, ii b)
         {
             if(a.first == b.first) return a.second < b.second;
             return a.first > b.first;
         });

    int idx;
    for(int i=0;i<n;i++)
    {
        if(sc[i].second == 0)
        {
            idx=i;
            break;
        }
    }

    cout << idx+1 <<endl;

    return 0;
}
