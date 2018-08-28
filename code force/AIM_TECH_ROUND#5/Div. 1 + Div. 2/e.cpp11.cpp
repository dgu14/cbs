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

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND


    Find any point where val[i] < val[i+1].
    Set ans[i+1] = val[i+1]. Then, for j = i, i-1, ..., i+2, set ans[j] = ans[j+1] + val[j].
    Then, in order to ensure the value is large enough, if ans[j] < 1e9, set ans[j] = ans[j] + 1e9 * ans[j+1].
    It's easy to verify that this works. 42175007
    Special cases are val[i] = val[j] != 0 for all i && j, in which case you answer NO, and val[i] = 0 for all i, in which case you just print a bunch of 1's.
*/

ll n, b[200000], ans[200000];
int main()
{
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n;
        forn(i,n) cin>>b[i];


        int p=-1;
        forn(i,n)
        {
            if(b[i]<b[(i+1)%n])
            {
                p=(i+1)%n; break;
            }
        }

        if(p==-1)
        {
            if(b[0]!=0)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                cout << "YES" << endl;
                forn(i,n)
                {
                    cout << 5;
                    if(i!=n-1) cout << ' ';
                }
                cout << endl;
                return 0;
            }
        }


        ans[p]=b[p];
        int r=p;
        ll const mofy=200000ll * ans[p];
        forn(i,n)
        {
            if(i==n-1) continue;
            int f=p-1;
            if(f<0)f+=n;

            ans[f]=b[f]+ans[(f+1)%n];

            p=f;
        }

        forn(i,n)
        {
            if(i!=r) ans[i]+=mofy;
        }

        cout << "YES" << endl;
        forn(i, n)
        {
            cout << ans[i] ;
            if(i!=n-1) cout << ' ';
        }

        cout << endl;

    #endif

	return 0;
}
