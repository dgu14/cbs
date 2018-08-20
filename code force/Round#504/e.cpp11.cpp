#include<bits/stdc++.h>
using namespace std;
string s,r,t;
int q(int a,int b,int c,int d) {
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cin>>s;
    return s=="YES";
}
int main() {
    int i,n,x,y;
    cin>>n;
    x=1,y=1;
    for(i=1;i<n;i++) {
        if(q(x+1,y,n,n)) x++,r+="D";
        else y++,r+="R";
    }
    x=n,y=n;
    for(i=1;i<n;i++) {
        if(q(1,1,x,y-1)) y--,t="R"+t;
        else x--,t="D"+t;
    }
    cout<<"! "<<r<<t;
}
