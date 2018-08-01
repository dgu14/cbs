#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll solve(ll n, ll tot_star, ll s_used, ll p_used)
{
    if(p_used < 2*s_used) return 0;
    if(s_used == tot_star)
    {
        if(n == 1) return 1;
        else return 0;
    }

    ll ret = 0;
    if(s_used != tot_star && n%3 == 0)
    {
        ret += solve(n/3, tot_star, s_used+1, p_used);
    }
    if(p_used != 2*tot_star)
    {
        ret += solve(n-1, tot_star, s_used, p_used+1);
    }

    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    int answer = 0;

    ll star=0;
    ll base=3, i=1;

    for(;;i++)
    {
        if(base + 2*i > n)
        {
            break;
        }


        base = 3 * base;
    }

    i--;

    answer = solve(n, i, 0, 0);


    return answer;
}


int main()
{
    int n;
    cin >> n;

    cout << solution(n) << endl;
    return 0;
}
