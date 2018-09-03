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

int n;
string a, b;
int main()
{
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n>>a>>b;

        string c;
        forn(i,n)
        {
            if(a[i]==b[i]) c+='2';
            else if(a[i]=='0') c+='0';
            else c+='1';
        }

        ll ret=0;
        forn(i,n-1)
        {
            if((c[i]=='1' && c[i+1]=='0')||(c[i]=='0' && c[i+1]=='1'))
            {
                c[i]='2'; c[i+1]='2';
                ret+=1;
            }
        }


        forn(i,n)
        {
            if(c[i]!='2') ret++;
        }

        cout << ret << endl;


    #endif

	return 0;
}

