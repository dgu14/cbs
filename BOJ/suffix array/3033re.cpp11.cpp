#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
int d;
V<int> group;

bool Compare(int i, int j)
{
    if(group[i] != group[j]) return group[i] < group[j];

    return group[i+d] < group[j+d];
}

int main()
{
    int ff;
    string str;
    cin >> ff;
    cin >> str;

    int n=str.size();
    vector<int> perm(n);
    group.resize(n+1);

    for(int i=0;i<n;i++)
    {
        perm[i]=i;
        group[i]=str[i];
    }

    group[n] = -1;

    for(d=1;;d*=2)
    {
        sort(perm.begin(), perm.end(), Compare);

        V<int> temp(n+1, 0);
        temp[n]=-1;
        for(int i=0;i<n-1;i++)
        {
            temp[perm[i+1]]=temp[perm[i]] + Compare(perm[i], perm[i+1]);
        }

        swap(group, temp);
        if(group[perm[n-1]]==n-1)break;
    }

    V<int> lcp(n-1);
    for(int i=0,k=0;i<n;i++,k=max(k-1,0))
    {
        if(group[i]==n-1) continue;

        for(int j=perm[group[i]+1];str[i+k]==str[j+k];k++);
        lcp[group[i]]=k;
    }

    int max_len=0;
    for(int i=0;i<n-1;i++)
    {
        max_len = max(max_len, lcp[i]);
    }

    cout << max_len <<endl;

    return 0;
}
