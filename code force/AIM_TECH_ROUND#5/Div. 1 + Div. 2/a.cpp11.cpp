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
*/

int n,m;
string table[200];

int main()
{
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n>>m;
        forn(i,n) cin>>table[i];

        int sx=-1,sy,ex,ey;
        forn(i, n)
        {
            forn(j, m)
            {
                if(table[i][j]=='B')
                {
                    if(sx==-1) { sx=i; sy=j; }
                    ex=i; ey=j;
                }
            }
        }


        cout << (sx+ex)/2 + 1 << " " << (sy+ey)/2 + 1<< endl;
    #endif

	return 0;
}
