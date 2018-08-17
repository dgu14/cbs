#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int n,k;
string sq;

int main()
{
    cin>>n>>k>>sq;
    int r=(n-k)/2;
    r=n/2-r;


    stack<string> stk;
    for(int i=0;i<n;i++)
    {
        if(sq[i]=='(')
        {
            stk.push("(");
        }
        else if(sq[i]==')')
        {
            string f=")";
            while(stk.top()!="(")
            {
                f=stk.top() + f;
                stk.pop();
            }
            stk.pop();
            f="("+f;

            stk.push(f);

            r--;
            if(r==0)
            {
                break;
            }
        }
    }

    string ret;
    while(stk.size())
    {
        if(stk.top().size()%2==0)
        {
            ret=stk.top()+ret;
        }
        stk.pop();
    }

    cout << ret << endl;

    return 0;
}
