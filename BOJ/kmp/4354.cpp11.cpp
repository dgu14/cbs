#include <bits/stdc++.h>
using namespace std;

// the smallest deviding number x , x^n must be found by kmp fail
// if there was a smaller one y(y^m), kmp fail value must be changed to m-1(m-1 > n-1)
// and if the string length s is multiple of s-kmp value, there is a x that x^n makes the string.

template <class T> using V = vector<T>;
int main()
{
    cin.tie(nullptr);
    string str;
    while(true)
    {
        cin >> str;
        if(str == ".") break;

        int s = str.size(), matched = 0;
        V<int> p(s, 0);

        for(int i=1;i<s;i++)
        {
            while(matched != 0 && str[i] != str[matched]) matched = p[matched-1];

            if(str[i] == str[matched]) matched++;
            p[i] = matched;
        }


        if(s%(s-p[s-1]) == 0)
        {
            cout << s/(s-p[s-1]) << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }

    return 0;
}
