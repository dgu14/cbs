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



int n;
int lx[150000], ux[150000], ly[150000], uy[150000];
ii prex[150000], prey[150000], sufx[150000], sufy[150000];

int main()
{
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n;
        forn1(i,n) cin>>lx[i]>>ly[i]>>ux[i]>>uy[i];
    #endif

        prex[0].first=(int)-1e9;
        prex[0].second=(int)1e9;

        prey[0].first=(int)-1e9;
        prey[0].second=(int)1e9;

        sufx[0].first=(int)-1e9;
        sufx[0].second=(int)1e9;

        sufy[0].first=(int)-1e9;
        sufy[0].second=(int)1e9;

        prex[n+1].first=(int)-1e9;
        prex[n+1].second=(int)1e9;

        prey[n+1].first=(int)-1e9;
        prey[n+1].second=(int)1e9;

        sufx[n+1].first=(int)-1e9;
        sufx[n+1].second=(int)1e9;

        sufy[n+1].first=(int)-1e9;
        sufy[n+1].second=(int)1e9;

        forn1(i,n)
        {
            prex[i].first=max(prex[i-1].first, lx[i]);
            prex[i].second=min(prex[i-1].second, ux[i]);

            prey[i].first=max(prey[i-1].first, ly[i]);
            prey[i].second=min(prey[i-1].second, uy[i]);


            sufx[n+1-i].first=max(sufx[n+2-i].first, lx[n+1-i]);
            sufx[n+1-i].second=min(sufx[n+2-i].second, ux[n+1-i]);

            sufy[n+1-i].first=max(sufy[n+2-i].first, ly[n+1-i]);
            sufy[n+1-i].second=min(sufy[n+2-i].second, uy[n+1-i]);
        }


        forn1(i,n)
        {
            if(prex[i-1].first > prex[i-1].second || prey[i-1].first > prey[i-1].second);
            else if(sufx[i+1].first > sufx[i+1].second || sufy[i+1].first > sufy[i+1].second);
            else if(prex[i-1].first > sufx[i+1].second || sufx[i+1].first > prex[i-1].second);
            else if(prey[i-1].first > sufy[i+1].second || sufy[i+1].first > prey[i-1].second);
            else
            {
                int cx=min(prex[i-1].second, sufx[i+1].second), cy=min(prey[i-1].second, sufy[i+1].second);
                cout << cx << ' ' << cy << endl;
                return 0;
            }
        }

	return 0;
}
