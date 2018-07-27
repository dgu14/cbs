#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n,k, a[100005], d[100005];

ll gcd(ll a, ll b)
{
    if(b>a) swap(a,b);

    if(b==0) return a;
    else return gcd(b, a%b);
}

int main()
{
    scanf("%d%d",&n, &k);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);


    ll g=a[0];
    for(int i=1;i<n;i++)
    {
        g = gcd(g, a[i]);
    }

    for(int i=0;i<k;i++)
    {
        d[(g*i)%k] = 1;
    }

    vector<int> ff;
    for(int i=0;i<k;i++)
    {
        if(d[i]) ff.push_back(i);
    }

    printf("%d\n", ff.size());
    for(int i=0;i<ff.size();i++)
    {
        printf("%d ", ff[i]);
    }
    printf("\n");


    return 0;
}
