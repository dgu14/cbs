#include <bits/stdc++.h>
using namespace std;


int n,q, arr[200005];

int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];

    bool isQExist=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==q) isQExist=true;
    }

    if(!isQExist)
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=q;
            isQExist=true;

            break;
        }
    }

    if(!isQExist)
    {
        cout << "NO" << endl;
        return 0;
    }


    int j;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=0)
        {
            j=i-1;
            while(j>=0 && arr[j] == 0)
            {
                arr[j]=arr[i];
                j--;
            }
        }
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=0)
        {
            j=i+1;
            while(j<n && arr[j] == 0)
            {
                arr[j]=arr[i];
                j++;
            }
        }
    }


    bool done[200005] ={false,};

    stack<int> stk;

    for(int i=0;i<n;i++)
    {
        if(done[arr[i]])
        {
            cout << "NO" << endl;
            return 0;
        }

        while(stk.size() && stk.top() > arr[i])
        {
            done[stk.top()]=true;
            stk.pop();
        }


        stk.push(arr[i]);
    }

    cout << "YES" << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
