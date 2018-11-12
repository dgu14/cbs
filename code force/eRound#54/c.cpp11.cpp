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

dbl det(dbl d)
{
    return d*d-4*d;
}

pair<dbl,dbl> solveb(dbl d)
{
    return {(d-sqrt(det(d)))/2, (d+sqrt(det(d)))/2};
}

pair<dbl,dbl> solvea(pair<dbl,dbl> b, dbl d)
{
    return {d-b.first, d-b.second};
}

int main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        dbl d;
        cin>>d;

        if(det(d)<0)
        {
            printf("N\n");
            continue;
        }

        pair<dbl,dbl> b=solveb(d);
        pair<dbl,dbl> a=solvea(b,d);


        if(a.second>=0 && b.second>=0)
        {
            printf("Y %.9f %.9f\n", a.second ,b.second);
            continue;
        }
        else if(a.first>=0 && b.first>=0)
        {
            printf("Y %.9f %.9f\n", a.first ,b.first);
            continue;
        }
        else
        {
            printf("N\n");
        }
    }
	return 0;
}

