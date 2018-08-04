#include <bits/stdc++.h>
using namespace std;


int fd[] = {500, 300, 200, 50, 30, 10};
int fn[] = {1,2,3,4,5,6};

int sd[] = {512, 256, 128, 64, 32};
int sn[] = {1, 2, 4, 8, 16};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int a, b;
        cin>>a>>b;

        int ra=-1, rb=-1;
        int i = 0;


        if(a==0) ra=-1;
        else
        for(;i<6;i++)
        {
            a-=fn[i];
            if(a<=0)
            {
                ra = i;
                break;
            }
        }

        i=0;

        if(b==0) rb=-1;
        else
        for(;i<5;i++)
        {
            b-=sn[i];
            if(b<=0)
            {
                rb = i;
                break;
            }
        }

        int s = 0;
        if(ra!=-1) s += fd[ra];
        if(rb!=-1) s += sd[rb];

        cout << s*10000 << '\n';
    }

    return 0;
}
