#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, ret;
    cin >> str;


    int onesCnt=0;
    for(int i=0;i<str.size();i++) if(str[i]=='1') onesCnt++;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='1')
        {
            ret += str[i];
        }
    }

    int p=ret.size();
    for(int i=0;i<ret.size();i++)
    {
        if(ret[i]=='2')
        {
            p=i;
            break;
        }
    }


    string ap;
    for(int i=0;i<onesCnt;i++) ap+='1';


    ret.insert(p, ap);
    cout << ret << endl;

    return 0;
}
