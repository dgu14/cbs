#include <bits/stdc++.h>
using namespace std;

double const eps=1e-9;
using ll=long long;
ll sy,a,b;
ll n, q, l[200005], r[200005], x[200005], y[200005], lseg[200005];

double solve(int itr)
{
    double s=-sy*(x[itr]-a);
    s=s/(y[itr]-sy) + a;

    double e=-sy*(x[itr]-b);
    e=e/(y[itr]-sy) + b;

    int si=upper_bound(r, r+n, s)-r;
    int ei=lower_bound(l, l+n, e)-l-1;

    if(si>ei) return 0.0f;

    double ret=0;

    if(si == ei)
    {
        if(l[si] >= s)
        {
            s=l[si];
        }

        if(r[ei] <= e)
        {
            e=r[ei];
        }

        return (e-s)*(y[itr]-sy)/y[itr];
    }

    if(l[si] < s)
    {
        ret += r[si]-s;
        si++;
    }

    if(r[ei] > e)
    {
        ret += e-l[ei];
        ei--;
    }

    if(si <= ei)
    {

        ret += lseg[ei];
        if(si != 0) ret -= lseg[si-1];
    }

    return ret * (y[itr]-sy)/y[itr];
}

int main()
{
    cin>>sy>>a>>b>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        lseg[i]=r[i]-l[i];
    }

    for(int i=1;i<n;i++)
    {
        lseg[i] = lseg[i-1]+lseg[i];
    }

    cin>>q;
    for(int i=0;i<q;i++) cin>>x[i]>>y[i];

    for(int i=0;i<q;i++)
    {
        printf("%.8f\n", solve(i));
    }

    return 0;
}
