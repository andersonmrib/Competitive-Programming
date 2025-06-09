#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int n;
  while(cin >> n){

    int repunit = 1, length = 1;
    while(repunit % n != 0){
      repunit = (repunit * 10 + 1) % n;
      length++;
    }
    cout << length << "\n";
  }

  return 0;
}
