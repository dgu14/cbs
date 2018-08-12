#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ii=pair<int,int>;
template <class T> using V=vector<T>;


int n, p[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];


    for(int i=1;i<=n;i++)
    {
        V<bool> visited(n+1, false);

        int curr=i, re=-1;
        while(true)
        {
            visited[curr]=true;
            curr=p[curr];
            if(visited[curr]) break;
        }

        cout << curr;
        if(i!=n) cout << ' ';
    }

    cout << endl;

    return 0;
}
