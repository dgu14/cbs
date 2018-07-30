#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii=pair<ll,ll>;
template <class T> using V = vector<T>;

ll n,m,q;
V<ii> rc;
V<int> xSort,ySort;

int main()
{
    cin>>n>>m>>q;
    rc=V<ii>(q);
    for(int i=0;i<q;i++)
    {
        cin >> rc[i].first >> rc[i].second;
        xSort.push_back(rc[i].first);
        ySort.push_back(rc[i].second);
    }



    sort(ySort.begin(), ySort.end());
    sort(xSort.begin(), xSort.end());



    if(q==0)
    {
        cout << n+m-1 << endl;
        return 0;
    }


    ll x1,x2,y1,y2;
    x1=x2=rc[0].first;
    y1=y2=rc[0].second;

    for(int i=1;i<q;i++)
    {
        x1 = min(x1, rc[i].first);
        x2 = max(x2, rc[i].first);

        y1 = min(y1, rc[i].second);
        y2 = max(y2, rc[i].second);
    }

    int maxT = 0;
    int maxPos = -1;
    int isX = true;

    for(int i=x1;i<=x2;i++)
    {
        int k =upper_bound(xSort.begin(), xSort.end(), i) - lower_bound(xSort.begin(), xSort.end(), i);
        if(k > maxT)
        {
           maxT = k;
            maxPos = i;
        }
    }

    for(int i=y1;i<=y2;i++)
    {
        int k =upper_bound(ySort.begin(), ySort.end(), i) - lower_bound(ySort.begin(), ySort.end(), i);
        if(k > maxT)
        {
            maxT = k;
            maxPos = i;
            isX=false;
        }
    }


    int tot = 0;

    if(isX)
    {
        for(int i=x1;i<=x2;i++)
        {
            if(i == maxPos) continue;
            if(binary_search(xSort.begin(), xSort.end(), i));
            else tot++;
        }

        tot += y2-y1+1-maxT;

    }
    else
    {
        for(int i=y1;i<=y2;i++)
        {
            if(i == maxPos) continue;
            if(binary_search(ySort.begin(), ySort.end(), i));
            else tot++;
        }

        tot += x2-x1+1-maxT;
    }

    ll rx = 0, ry = 0;

    rx = n-(x2-x1)-1;
    ry = m-(y2-y1)-1;

    cout << tot + rx + ry << endl;

    return 0;
}
