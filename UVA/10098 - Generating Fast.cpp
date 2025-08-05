#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  while(n--){

    string str; cin >> str;
    sort(str.begin(), str.end());

    do{
      cout << str << "\n";
    } while(next_permutation(str.begin(), str.end()));

    cout << "\n";
  }

  return 0;
}
