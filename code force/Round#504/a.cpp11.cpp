#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
using ll=long long;
using ii=pair<ll,ll>;

int N,M;
string a, b;

int main()
{
    cin>>N>>M>>a>>b;

    int i=0,j=0;
    N=a.size();M=b.size();

    bool isStarExist =false;
    for(i=0;i<N;i++)
    if(a[i]=='*')
    {
        isStarExist=true;
        break;
    }


    if(isStarExist)
    {
        if(b.substr(0, i) == a.substr(0, i))
        {
            bool test=true;
            for(j=0;;j++)
            {
                if(N-1-j == i) break;
                if(a[N-1-j] != b[M-1-j]) test=false;
                if(M-1-j == i-1) test=false;
            }

            if(test)
            {
                cout << "YES" << endl;
                return 0;
            }
        }

        cout <<"NO" << endl;

        return 0;
    }
    else{
        if(a==b)
        {
            cout << "YES" << endl;

        }
        else cout << "NO" << endl;

        return 0;
    }


    return 0;
}
