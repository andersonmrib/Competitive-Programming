#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n; cin >> n;
    int cur, low = 0, high = 0;
    for(int i=0; i<n; i++){

      int h; cin >> h;
      if(!i) cur = h;
      else{
        if(h > cur){
          high++;
          cur = h;
        }

        else if(h < cur){
          low++;
          cur = h;
        }
      }
    }
    cout << "Case " << ++NC << ": " << high << " " << low << "\n";
  }

  return 0;
}


