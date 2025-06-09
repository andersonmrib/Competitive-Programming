#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){
    int y1, m1, d1, y2, m2, d2;
    char d; // dummy
    cin >> y1 >> d >> m1 >> d >> d1;
    cin >> y2 >> d >> m2 >> d >> d2;

    struct tm date1 = {};
    date1.tm_year = y1 - 1900;;
    date1.tm_mon = m1 - 1;
    date1.tm_mday = d1;

    struct tm date2 = {};
    date2.tm_year = y2 - 1900;;
    date2.tm_mon = m2 - 1;
    date2.tm_mday = d2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    int ans = abs(difftime(time1, time2)/(60*60*24));
    cout << ans << "\n";
  }

  return 0;
}
