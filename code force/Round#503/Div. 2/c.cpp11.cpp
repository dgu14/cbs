#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ii=pair<int,int>;
template <class T> using V=vector<T>;

int n,m;
vector<int> p[3003];
vector<ii> sortedArr;
int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        p[a].push_back(b);
    }

    for(int i=1;i<=m;i++)
    {
        sort(p[i].begin(), p[i].end());
        for(int j=0;j<p[i].size();j++) sortedArr.push_back({p[i][j],i});
    }

    sort(sortedArr.begin(), sortedArr.end());



    ll min_cost=1e18;

    for(int i=1;i<=n;i++)
    {
        if(p[1].size() > i) continue;

        int sub[3003] = {0,}, totsub=0;
        ll cost=0;
        for(int j=2;j<=m;j++)
        {
            if(p[j].size()>=i)
            {
                totsub+=p[j].size()-i+1;
                sub[j]=p[j].size()-i+1;

                for(int k=0;k<sub[j];k++)
                {
                    cost+=p[j][k];
                }
            }
        }

        int f=p[1].size()+totsub;
        if(f > i) continue;


        for(int j=0;f!=i && j<sortedArr.size();j++)
        {
            int idx=sortedArr[j].second;
            if(idx==1) continue;
            if(sub[idx]==0)
            {
                cost+=sortedArr[j].first;
                f++;
            }
            else sub[idx]--;
        }

        min_cost=min(min_cost, cost);
    }

    cout << min_cost <<endl;

    return 0;
}
