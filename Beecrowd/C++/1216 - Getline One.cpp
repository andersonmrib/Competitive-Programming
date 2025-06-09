#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  string str;
  double ans = 0, number;
  int coun = 0;

  while(getline(cin, str)){
    cin >> number;
    cin.ignore();
    ans += number;
    coun++;
  }

  printf("%.1lf\n", ans/coun);

  return 0;
}
