#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ii=pair<int,int>;
int n,k;
string sq;

int main()
{
    cin>>n>>k>>sq;
    int r=(n-k)/2;
    r=n/2-r;


    string nsq;
    vector<int> excl;
    for(int i=0;i<n;i++)
    {
        if(sq[i]==')')
        {
            if(!r) continue;
            nsq += sq[i]; r--;
        }
        else  nsq += sq[i];
    }

    int m=nsq.size();

    stack<int> stk;

    for(int i=0;i<m;i++)
    {
        if(nsq[i]=='(') stk.push(i);
        else
        {
            stk.pop();
        }
    }

    while(stk.size())
    {
        excl.push_back(stk.top());
        stk.pop();
    }

    reverse(excl.begin(), excl.end());

    for(int i=0, j=0;i<m;i++)
    {
        if(j<excl.size() && i==excl[j])
        {
            j++;
        }
        else cout << nsq[i];
    }
    cout << endl;

    return 0;
}
