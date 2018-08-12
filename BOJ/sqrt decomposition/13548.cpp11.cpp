#include <bits/stdc++.h>
using namespace std;

class triple
{
public:
    int x, y, z;
};

int n, m, sn, arr[100005], cnt[100005];
int fa[100005] = {0,}, maxx=0;

triple q[100005];
void add(int c)
{
    if(c>=100001) exit(0);
    fa[c]--;
    fa[c+1]++;
    maxx=max(maxx, c+1);
}

void del(int c)
{
    if(c<=0) exit(0);
    fa[c]--;
    fa[c-1]++;
    if(fa[c]==0 && maxx==c)
    {
        maxx-=1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>q[i].x>>q[i].y;
        q[i].z=i;
        q[i].x--;q[i].y--;
    }

    int sn=sqrt(n);
    sort(q, q+m, [&sn](triple& a, triple& b)
         {
             if(a.x/sn == b.x/sn) return a.y < b.y;
             return a.x/sn < b.x/sn;
         });

    int answer[100005], ret[100005];

    for(int i=q[0].x;i<=q[0].y;i++)
    {
        add(cnt[arr[i]]);
        cnt[arr[i]]++;
    }
    answer[0]=maxx;

    for(int i=1;i<m;i++)
    {
        if(q[i].y > q[i-1].y)
        {
            for(int j=q[i-1].y+1;j<=q[i].y;j++)
            {
                add(cnt[arr[j]]);
                cnt[arr[j]]++;
            }
        }

        if(q[i].x < q[i-1].x)
        {
            for(int j=q[i].x;j<q[i-1].x;j++)
            {
                add(cnt[arr[j]]);
                cnt[arr[j]]++;
            }
        }

        if(q[i].x > q[i-1].x)
        {
            // del
            for(int j=q[i-1].x;j<q[i].x;j++)
            {
                del(cnt[arr[j]]);
                cnt[arr[j]]--;
            }
        }


        if(q[i].y < q[i-1].y)
        {
            for(int j=q[i].y+1;j<=q[i-1].y;j++)
            {
                del(cnt[arr[j]]);
                cnt[arr[j]]--;
            }
        }




        answer[i] = maxx;
    }

    for(int i=0;i<m;i++)
    {
        ret[q[i].z]=answer[i];
    }

    for(int i=0;i<m;i++)
    {
        cout << ret[i] << '\n';
    }

    return 0;
}

