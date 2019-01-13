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

ll l,w,h,n,a,b,c;
ll nums[21];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>l>>w>>h>>n;

    forn(i,n)
    {
        cin>>a>>b;
        if(a>20) continue;
        nums[a]+=b;
    }

    ll rl=l, rw=w, rh=h;
    ll base=1, ret=0;

    forn(i, 20) base*=2;

    rforn(i, 21)
    {
        ll la=rl/base, wa=rw/base, ha=rh/base;
        // 큰부피-작은부피
        ll inla=(l-rl)/base, inwa=(w-rw)/base, inha=(h-rh)/base;
        ll lft=(inla+la)*(inwa+wa)*(inha+ha)-inla*inwa*inha;

        if(lft==0)
        {
            base/=2;
            continue;
        }

        if(lft>nums[i])
        {
            ret+=nums[i];
            ll j;
            ll cll=nums[i];
            ll clft=lft;
            nums[i]=0;
            for(j=i-1;j>=0;j--)
            {
                cll*=8;
                clft*=8;
                cll+=nums[j];
                ret+=nums[j];

                if(cll>=clft)
                {
                    cll-=clft;
                    nums[j]=cll;
                    ret-=cll;
                    break;
                }
                else
                {
                    nums[j]=0;
                }
            }

            if(j==-1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
        else
        {
            nums[i]-=lft;
            ret+=lft;
        }

        rl-=la*base;
        rw-=wa*base;
        rh-=ha*base;

        base/=2;
    }

    if(rl==0 && rw==0 && rh==0)
    {
        cout << ret << endl;
    }
    else cout << -1 << endl;


	return 0;
}

/*

10 10 11
3
0 101
1 80
2 7
-1
*/
