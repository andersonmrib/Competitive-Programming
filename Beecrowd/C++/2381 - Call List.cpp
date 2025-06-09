#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n, k; cin >> n >> k;
  set<string> names;
  string name;

  while(n--){
    cin >> name;
    names.insert(name);
  }

  for(auto n : names){
    k--;
    if(!k) cout << n << endl;
  }

  return 0;
}
