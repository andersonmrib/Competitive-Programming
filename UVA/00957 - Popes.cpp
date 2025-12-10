#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int y;
  while(cin >> y){

    int p; cin >> p;

    vector<int> dates(p);
    for(int i=0; i<p; i++)
      cin >> dates[i];

    int ans = 0, first = 0, last = 0;
    for(int i=0; i<p; i++){

      int limit = dates[i] + y - 1;
      auto it = upper_bound(dates.begin(), dates.end(), limit);

      int ctt = it - (dates.begin() + i);
      if(ctt > ans){
        ans = ctt;
        first = dates[i];
        last = *(it - 1);
      }
    }

    cout << ans << " " << first << " " << last << endl;
  }

  return 0;
}
