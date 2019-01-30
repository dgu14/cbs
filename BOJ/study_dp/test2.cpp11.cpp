#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

bool cmpp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
   if (abs(a.second.second - a.second.first) > abs(b.second.second - b.second.first)) {
      return true;
   }
   return false;
}

int main() {
   int n, a, b;

   while(true)
   {
       vector<pair<int, pair<int, int> > > v;
        cin >> n >> a >> b;
        if(n==0 && a==0 && b==0) break;

       for (int i = 0; i < n; i++) {
          int k, ad, bd;
          cin >> k >> ad >> bd;
          v.push_back(make_pair(k, make_pair(ad, bd)));
       }
       sort(v.begin(), v.end(), cmpp);

       int res = 0;
       for (int i = 0; i < n; i++) {
          int da = v[i].second.first, db = v[i].second.second;
          if (da >= db) { //b방이 더 가깝거나 동일
             while (b && v[i].first) {
                res += v[i].second.second;
                b--;
                v[i].first--;
             }
             if (v[i].first > 0) {
                while (a && v[i].first) {
                   res += v[i].second.first;
                   a--;
                   v[i].first--;
                }
             }
          }
          else { //a방이 더 가까움

             while (a && v[i].first) {
                res += v[i].second.first;
                a--;
                v[i].first--;
             }
             if (v[i].first > 0) {
                while (b && v[i].first) {
                   res += v[i].second.second;
                   b--;
                   v[i].first--;
                }
             }
          }
       }
       cout << res << '\n';
   }

   return 0;
}
