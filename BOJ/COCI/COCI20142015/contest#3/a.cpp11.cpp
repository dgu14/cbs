#include <bits/stdc++.h>
using namespace std;

int pressed[8];
string str, cls[8]={"1QAZ","2WSX","3EDC","45RTFGVB","67YUHJNM", "8IK,", "9OL.","0-=P[];'/"};

int fd(char ch)
{
    for(int i=0;i<8;i++)
    {
        if(cls[i].find(ch) != string::npos) return i;
    }

    return -1;
}
int main()
{
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        pressed[fd(str[i])] ++;
    }

    for(int i=0;i<8;i++) cout << pressed[i] << endl;

    return 0;
}
