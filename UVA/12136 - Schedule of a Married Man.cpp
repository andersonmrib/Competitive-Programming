#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  int NC = 0;
  while(n--){

    string st1, st2, st3, st4;
    cin >> st1 >> st2 >> st3 >> st4;
    int h1, m1, h2, m2;
    sscanf(st1.c_str(), "%d:%d", &h1, &m1);
    sscanf(st2.c_str(), "%d:%d", &h2, &m2);
    int hm1, mm1, hm2, mm2;
    sscanf(st3.c_str(), "%d:%d", &hm1, &mm1);
    sscanf(st4.c_str(), "%d:%d", &hm2, &mm2);

    int a = h1*60+m1, b = h2*60+m2;
    int c = hm1*60+mm1, d = hm2*60+mm2;

    if((c >= a && c <= b) || (d >= a && d <= b) || (c <= a && d >= b))
      cout << "Case " << ++NC << ": Mrs Meeting\n";
    else
      cout << "Case " << ++NC << ": Hits Meeting\n";
  }

  return 0;
}
