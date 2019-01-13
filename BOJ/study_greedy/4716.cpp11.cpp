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

    while(true)
    {
        int n,a,b, ret=0;
        int da[1005], db[1005], dc[1005];
        cin>>n>>a>>b;

        if(n==0 && a==0 && b==0) break;
        forn(i,n) cin>>dc[i]>>da[i]>>db[i];

        priority_queue<ii, V<ii>, greater<ii>> pqa, pqb;
        int ra=a, rb=b;

        forn(i,n)
        {
            if(da[i]<db[i])
            {
                // a¿¡ ³Ö¾î¾ßÇÔ , (ÀüÈ¯ºñ¿ë, °¹¼ö)
                pqa.push({db[i]-da[i], dc[i]});
                ret+=da[i]*dc[i];
                ra-=dc[i];

                // ¸¸¾à ²Ë Âû °æ¿ì, ²ËÂ÷´Â¸¸¤»¹Ç »©¾ßÇÔ
                if(ra<0)
                {
                    while(ra<0)
                    {
                        ii ttp=pqa.top(); pqa.pop();

                        if(ttp.second>-ra)
                        {
                            pqb.push({INF, -ra});
                            pqa.push({ttp.first, ttp.second+ra});
                            ret+=ttp.first*(-ra);
                            ra=0;
                        }
                        else
                        {
                            pqb.push({INF, ttp.second});
                            ret+=ttp.first*ttp.second;
                            ra+=ttp.second;
                        }
                    }
                }
            }
            else
            {
                // b
                pqb.push({da[i]-db[i], dc[i]});
                ret+=db[i]*dc[i];
                rb-=dc[i];

                // ¸¸¾à ²Ë Âû °æ¿ì, ²ËÂ÷´Â¸¸¤»¹Ç »©¾ßÇÔ
                if(rb<0)
                {
                    while(rb<0)
                    {
                        ii ttp=pqb.top(); pqb.pop();

                        if(ttp.second>-rb)
                        {
                            pqa.push({INF, -rb});
                            pqb.push({ttp.first, ttp.second+rb});
                            ret+=ttp.first*(-rb);
                            rb=0;
                        }
                        else
                        {
                            pqa.push({INF, ttp.second});
                            ret+=ttp.first*ttp.second;
                            rb+=ttp.second;
                        }
                    }
                }
            }
        }
        cout << ret << endl;
    }

	return 0;
}

/*
2 5 5
5 10 200
5 15 2000
0 0 0
*/
