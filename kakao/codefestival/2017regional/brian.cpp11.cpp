#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
template <class T> using V = vector<T>;
string solution(string sentence) {
    string answer = "";
    int len = sentence.size();

    V<int> ns[26];
    for(int i=0;i<len;i++)
    {
        if(sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            ns[sentence[i]-'a'].push_back(i);
        }
    }

    int law[26] = {0,};

    for(int i=0;i<26;i++)
    {
        for(int j=i+1;j<26;j++)
        {
            if(ns[i].size() == 2 && ns[j].size() == 2)
            {
                if(ns[i][0] > ns[j][1] || ns[j][0] > ns[i][1]) continue;

                if(ns[i][1] - ns[i][0] == 2 && ns[i][0] == ns[j][0] + 2 && ns[i][1] == ns[j][1] - 2)
                {
                    law[i] = 1;
                    law[j] = 2;
                    continue;
                }

                if(ns[j][1] - ns[j][0] == 2 && ns[j][0] == ns[i][0] + 2 && ns[j][1] == ns[i][1] - 2)
                {
                    law[i] = 2;
                    law[j] = 1;
                    continue;
                }

                return "invalid";
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        if(ns[i].size() == 2 && law[i] == 0)
        {
            law[i] = 2;
            if(ns[i][1] -ns[i][0] == 1) return "invalid";
        }
    }

    for(int i=0;i<26;i++)
    {
        if(ns[i].size() >= 1 && (law[i] == 0 || law[i] == 1));
        else continue;

        if(ns[i][0]-1<0 || (sentence[ns[i][0]-1] >= 'a' && sentence[ns[i][0]-1] <= 'z')) return "invalid";
        if(ns[i][ns[i].size()-1]+1 >= len || (sentence[ns[i][ns[i].size()-1]+1] >= 'a' && sentence[ns[i][ns[i].size()-1]+1] <= 'z')) return "invalid";

        int prev=-1;
        for(int j=1;j<ns[i].size();j++)
        {
            int test = ns[i][j] - ns[i][j-1];
            if(prev == -1) prev=test;
            else
            {
                if(test != prev) return "invalid";
            }
        }

        for(int j=1;j<ns[i].size();j++)
        {
            int idx = ns[i][j]-1;
            if(sentence[idx] >= 'a' && sentence[idx] <= 'z') return "invalid";
        }

        law[i] = 1;
    }


    for(int i=0;i<26;i++)
    {
        for(int j=i+1;j<26;j++)
        {
            if(law[i] == 1 && law[j] == 1)
            {
                int imin = ns[i][0]-1;
                int imax = ns[i][ns[i].size()-1]+1;

                int jmin = ns[j][0]-1;
                int jmax = ns[j][ns[j].size()-1]+1;

                if(imax < jmin || jmax < imin) continue;

                return "invalid";
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(law[i] == 1 && law[j] == 2)
            {

                int imin = ns[i][0]-1;
                int imax = ns[i][ns[i].size()-1]+1;

                int jmin = ns[j][0]+1;
                int jmax = ns[j][1]-1;


                if(imin == jmin && imax == jmax) continue;
                if(imax < jmin || jmax < imin) continue;

                return "invalid";
            }
        }
    }


    V<int> dp(1005, -1);
    for(int i=0;i<26;i++)
    {
        if(law[i] == 1)
        {
            dp[ns[i][0]-1] = 0;
            dp[ns[i][ns[i].size()-1]+1] = 1;
        }
        else if(law[i] == 2)
        {
            dp[ns[i][0]+1] = 0;
            dp[ns[i][1]-1] = 1;

            if(ns[i][0]+1 == ns[i][1]-1) dp[ns[i][0]+1] = 2;
        }
    }


    for(int i=0;i<len;i++)
    {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            if(dp[i] == 0 || dp[i] == 2)
            {
                answer+=' ';
            }

            answer+=sentence[i];

            if(dp[i] == 1 || dp[i] == 2)
            {
                answer += ' ';
            }
        }
    }

    int firstChar=answer.size();
    for(int i=0;i<answer.size();i++)
    {
        if(answer[i] >= 'A' && answer[i] <= 'Z')
        {
            firstChar = i;
            break;
        }
    }

    answer = answer.substr(firstChar);
    if(answer[answer.size()-1] == ' ') answer = answer.substr(0, answer.size()-1);

    string ret;
    for(int i=0;i<answer.size();i++)
    {
        if(i>=1 && answer[i] == ' ' && answer[i-1] == ' ') continue;
        ret += answer[i];
    }

    return ret;
}


int main()
{
    string s;
    cin >> s;
    cout << solution(s) << endl;
    return 0;
}
