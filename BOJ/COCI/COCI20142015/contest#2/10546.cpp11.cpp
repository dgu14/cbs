#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
map<string, int> m;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string name;

    for(int i=0;i<n;i++)
    {
        cin >> name;
        m[name] ++;
    }


    for(int i=0;i<n-1;i++)
    {
        cin >> name;
        m[name] --;

        if(m[name] == 0) m.erase(name);
    }

    cout << m.begin()->first << endl;

    return 0;
}
