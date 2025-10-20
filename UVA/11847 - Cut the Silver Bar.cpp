#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n;
  while(cin >> n, n){
    cout << (int)log2(n) << endl;
  }

  return 0;
}
