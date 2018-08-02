#include <bits/stdc++.h>
using namespace std;

int l;
string s;
int p[1000005];
int main()
{
    cin >> l >> s;


    int matched = 0;
    for(int i=1;i<s.size();i++)
    {
        while(matched != 0 && s[i] != s[matched]) matched = p[matched-1];

        if(s[i] == s[matched])
        {
            matched++;
            p[i] = matched;
        }
    }


    cout << s.size() - p[s.size()-1] << endl;

    return 0;
}
