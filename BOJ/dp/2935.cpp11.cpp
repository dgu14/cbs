#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)
#define for1(i,p,q)                 for(int i=(int)p;i<=q;i++)
#define rfor1(i,p,q)                for(int i=(int)q;i>=p;i--)

string a,b,op;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>a>>op>>b;

    if(op=="*")
    {
        int c=a.size()-1+b.size()-1;
        string ret="1";

        while(c--)
        {
            ret+="0";
        }

        cout << ret << endl;
    }
    else
    {

        if(a.size()==b.size())
        {
            string ret="2";
            int c=a.size()-1;

            while(c--)
            {
                ret+="0";
            }

            cout << ret << endl;
        }
        else
        {
            string ret="1";
            int c=max((int)a.size(), (int)b.size())-1;

            while(c)
            {
                if(c==b.size() || c==a.size()) ret+="1";
                else ret+="0";
                c--;
            }

            cout << ret << endl;
        }
    }

	return 0;
}

