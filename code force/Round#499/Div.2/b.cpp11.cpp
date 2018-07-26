#include <bits/stdc++.h>
using namespace std;

int n,m,t,a[105];
map<int,int> M;

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> t;
        if(M[t]) M[t]++;
        else M[t] = 1;
    }


    int days = 1;

    for(;days<=100;days++)
    {
        int gatsu = 0;
        for(auto it = M.begin();it!=M.end();it++)
        {
            gatsu += (it->second)/days;
        }

        if(gatsu < n) break;
    }

    cout << days-1 << endl;



    return 0;
}
