#include <bits/stdc++.h>
using namespace std;

int value(char c){
switch(c){
  case '0': return 6;
  case '1': return 2;
  case '2': return 5;
  case '3': return 5;
  case '4': return 4;
  case '5': return 5;
  case '6': return 6;
  case '7': return 4;
  case '8': return 7;
  case '9': return 6;
 }
}

int main(){

  int n; cin >> n;
  while(n--){
    string str; cin >> str;

    int ans = 0;
    for(auto c : str)
      ans += value(c);

    cout << ans << " leds\n";
  }
  return 0;
}
