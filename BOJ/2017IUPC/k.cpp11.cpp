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

ll a,b,n,sca,scb;
bool sieve[5000005], used[5000005];
V<ll> aa,bb;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    sieve[0]=sieve[1]=1;

    for(int i=2;i*i<=5000000;i++)
    {
        if(sieve[i]==0)
        for(int j=i*2;j<=5000000;j+=i)
        {
            sieve[j]=1;
        }
    }

    forn(i,n)
    {
        cin>>a>>b;

        if(sieve[a])
        {
            if(bb.size()==3)
            {
                scb+=bb[0];
            }
            else scb+=1000;
        }
        else
        {
            if(used[a])
            {
                sca-=1000;
            }
            else
            {
                aa.push_back(a);
                sort(aa.begin(),aa.end());

                if(aa.size()>3) aa.erase(aa.begin());
                used[a]=1;
            }
        }

        if(sieve[b])
        {
            if(aa.size()==3)
            {
                sca+=aa[0];
            }
            else sca+=1000;
        }
        else
        {
            if(used[b])
            {
                scb-=1000;
            }
            else
            {
                bb.push_back(b);
                sort(bb.begin(),bb.end());

                if(bb.size()>3)bb.erase(bb.begin());
                used[b]=1;
            }
        }
    }

    //cout << aa.size() << ", " << bb.size() << endl;

    if(sca>scb)
    {
        cout << "소수의 신 갓대웅" << endl;
    }
    else if(scb>sca)
    {
        cout << "소수 마스터 갓규성" << endl;
    }
    else cout << "우열을 가릴 수 없음" << endl;

	return 0;
}

