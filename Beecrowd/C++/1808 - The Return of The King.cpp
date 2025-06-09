#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str; cin >> str;

  int sum = 0, numbers = 0;
  for(int i=0; i<str.size(); i++){
    sum += str[i] - '0';
    if(str[i] == '0') sum += 9;
    if(str[i] != '0') numbers++;
  }

  cout << fixed << setprecision(2);
  cout << double(sum)/(double)numbers << "\n";

  return 0;
}
