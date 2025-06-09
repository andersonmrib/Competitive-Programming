#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

ii getMinBase(string s){
  int base = 0, sum = 0;
  for(auto c : s){
    if(c >= '0' && c <= '9') { base = max(base, c - '0' + 1); sum += c - '0'; }
    else if(c >= 'A' && c <= 'Z') { base = max(base, c - 'A' + 10 + 1); sum += c - 'A' + 10; }
    else if(c >= 'a' && c <= 'z') { base = max(base, c - 'a' + 36 + 1); sum += c - 'a' + 36; }
    else continue;
  }
  ii getIt = {base, sum};
  return getIt;
}

int main(){

  speedBoost;
  string number;
  while(cin >> number){
    ii pairs = getMinBase(number);
    // The base must be greater or equal to 2
    int minBase = max(pairs.first, 2), sum = pairs.second;
    bool hasSolution = false;
    for(int i=minBase; i<=62; i++){
      if(sum%(i-1) == 0){
        cout << i << "\n";
        hasSolution = true;
        break;
      }
    }

    if(!hasSolution) cout << "such number is impossible!\n";
  }

  return 0;
}
