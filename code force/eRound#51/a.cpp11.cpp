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

    int tt;
    cin>>tt;

    while(tt--)
    {
        string str;
        cin>>str;

        bool d=false,u=false,l=false;
        int cnd=0,  cnu=0, cnl=0;
        int cndp=-1, cnup=-1, cnlp=-1;
        forn(i,str.size())
        {
            if(str[i]>='0' && str[i]<='9') d=true, cnd++, cndp=i;
            if(str[i]>='a' && str[i]<='z') l=true, cnl++, cnlp=i;
            if(str[i]>='A' && str[i]<='Z') u=true, cnu++, cnup=i;
        }

        int c=d+u+l;

        if(c==3)
        {
            cout << str << '\n';
        }
        else if(c==2)
        {
            if(!d)
            {
                if(cnl>=2)
                {
                    str[cnlp]='0';
                }
                else if(cnu>=2) str[cnup]='0';
            }
            else if(!l)
            {
                if(cnd>=2)
                {
                    str[cndp]='a';
                }
                else if(cnu>=2)
                {
                    str[cnup]='a';
                }
            }
            else if(!u)
            {
                if(cnd>=2)
                {
                    str[cndp]='A';
                }
                else if(cnl>=2)
                {
                    str[cnlp]='A';
                }
            }

            cout << str << '\n';
        }
        else if(c==1)
        {
            if(d)
            {
                str[0]='a'; str[1]='A';
            }
            else if(u)
            {
                str[0]='0'; str[1]='a';
            }
            else if(l)
            {
                str[0]='0'; str[1]='A';
            }

            cout << str << '\n';
        }
    }

	return 0;
}

