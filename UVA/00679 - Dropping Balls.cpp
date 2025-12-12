#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int d, I; cin >> d >> I;

    int k = 1;
    for(int i=0; i<d-1; i++){
      if((I&1)){
        k = k * 2;
        I = (I+1)/2;
      }
      else{
        k = k * 2 + 1;
        I = I/2;
      }
    }

    cout << k << endl;
  }

  int constant;
  cin >> constant;

  return 0;
}
