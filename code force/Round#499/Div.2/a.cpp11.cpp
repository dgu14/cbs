#include <bits/stdc++.h>
using namespace std;

int n,k;
string str;
int main()
{
    cin >> n >> k >> str;

    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());


    string ret;
    int prev = -99;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]-'a'+1 - prev >= 2)
        {
            ret += str[i];
            prev = str[i]-'a'+1;

            if(ret.size() == k) break;
        }
    }

    if(ret.size() != k)
    {
        cout << -1 << endl;
    }
    else
    {

        int s = 0;
        for(int i=0;i<ret.size();i++)
        {
            s += ret[i]-'a'+1;
        }

        cout << s << endl;
    }



    return 0;
}
