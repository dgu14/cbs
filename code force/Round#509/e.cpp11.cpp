#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

int n, a[1005], b[1005], p[1005], cnt[1005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n-1) cin>>a[i]>>b[i];

    forn1(i,n-1)
    {
        if(b[i] != n)
        {
            cout << "NO" << endl;
            return 0;
        }

        p[a[i]]=b[i];
        cnt[a[i]]++;
    }

    if(p[n-1]==0)
    {
        cout << "NO" << endl;
        return 0;
    }

    queue<int> cts;

    int ct=0;
    forn1(i,n-1)
    {
        if(p[i]==0)
        {
            ct++; cts.push(i);
        }
        else
        {
            cnt[i]--;
            ct-=cnt[i];

            if(ct<0)
            {
                cout << "NO" << endl;
                return 0;
            }

            while(cnt[i]--)
            {
                int ctst=cts.front(); cts.pop();
                p[ctst]=p[i];
                p[i]=ctst;
            }
        }
    }

    cout << "YES" << '\n';
    forn1(i,n-1)
    {
        cout << i << ' ' << p[i] << '\n';
    }

	return 0;
}

