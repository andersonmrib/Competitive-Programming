#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int amp, freq; cin >> amp >> freq;

    for(int f=0; f<freq; f++){
      // Prints the upper body
      for(int i=1; i<=amp; i++){
        for(int j=1; j<=i; j++){
          cout << i;
        }
        cout << endl;
      }

      // Prints the lower body
      for(int i=amp-1; i>=1; i--){
        for(int j=i; j>=1; j--){
          cout << i;
        }
        cout << endl;
      }

      if(f < freq-1) cout << endl;
    }

    if(t) cout << endl;
  }

  return 0;
}
