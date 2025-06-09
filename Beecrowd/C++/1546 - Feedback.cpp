#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

string solve(int a){
  if(a == 1)      return "Rolien";
  else if(a == 2) return "Naej";
  else if(a == 3) return "Elehcim";
  else if(a == 4) return "Odranoel";
}

int main(){

  int n; cin >> n;
  while(n--){
    int k; cin >> k;
    for(int i=0; i<k; i++){
      int op; cin >> op;
      cout << solve(op) << endl;
    }
  }

  return 0;
}
