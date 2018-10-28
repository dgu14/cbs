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

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string str;
    cin>>str;

    int cnt=0;
    char val[2];
    int ret[1005]={0,};

    forn(i, str.size())
    {
        if(cnt==0 || cnt==1)
        {
            if(val[cnt-1]!=str[i]) val[cnt++]=str[i];
        }
        else
        {
            if(val[cnt-1]!=str[i])
            {
                reverse(str.begin(), str.begin()+i);
                swap(val[0], val[1]);
                ret[i-1]=1;
            }
        }
    }

    if(val[0]=='b')
    {
        ret[str.size()-1]=1;
    }

    forn(i,str.size())
    {
        cout << ret[i] << ' ';
    }
    cout << endl;

	return 0;
}


