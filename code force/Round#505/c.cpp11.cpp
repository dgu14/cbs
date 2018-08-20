#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<ll,ll>;
template<class T> using V=vector<T>;

string str;
int main()
{
    cin>>str;

    char cc=str[0];
    int n=str.size();
    int c=1, m=0;

    for(int i=1;i<n;i++)
    {
        if(str[i] != cc)
        {
            c++;
        }
        else
        {
            m=max(m,c);
            c=1;
        }

        cc=str[i];
    }

    m=max(m,c);

    if(m==n)
    {
        cout << m << endl;
    }
    else
    {
        if(str[0]==str[n-1])
        {
            cout << m << endl;
            return 0;
        }

        c=1;
        cc=str[0];

        for(int i=1;i<n;i++)
        {
            if(str[i] != cc)
            {
                c++;
            }
            else break;

            cc=str[i];
        }

        int d=1;
        cc=str[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(str[i] != cc)
            {
                d++;
            }
            else break;

            cc=str[i];
        }

        m=max(m, c+d);

        cout << m << endl;
    }

    return 0;
}

