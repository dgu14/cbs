#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int,int>;
int x[10], a;
int dx[] = {0, 3, 3, 3, 3, 3, 4, 3, 4};


ii getInfo(char a)
{
    int tot = a-'a'+1;
    for(int i=0;i<9;i++)
    {
        tot-= dx[i];
        if(tot <= 0)
        {
            return {i, tot+dx[i]};
        }
    }
}

string getKeyCode(string str)
{
    string code;
    int prev = -1;
    for(int i=0;i<(int)str.size();i++)
    {
        ii curr=getInfo(str[i]);

        if(prev == curr.first)
        {
            code += '#';
        }
        for(int j=0;j<curr.second;j++) code += '1' + curr.first;
        prev = curr.first;
    }

    return code;
}


int main()
{
    for(int i=0;i<9;i++)
    {
        cin >> a;
        x[a] = (i+1);
    }

    string str;
    cin >> str;
    str = getKeyCode(str);


    for(int i=0;i<str.size();i++)
    {
        if(str[i] >= '1' && str[i] <= '9')
        {
            str[i] = x[str[i]-'0'] + '0';
        }
    }

    cout << str << endl;

    return 0;
}
