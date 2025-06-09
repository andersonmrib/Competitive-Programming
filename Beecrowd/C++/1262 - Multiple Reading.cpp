#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str;
  int P;

  while(cin >> str >> P){

    int ctt = 0, ans = 0;
    for(auto c : str){
      if( c == 'W'){
        ans++;
        if(ctt > 0){
          ans++;
          ctt = 0;
        }
      }
      else{
        ctt++;
        if(ctt == P){
          ans++;
          ctt = 0;
        }
      }
    }

    if(ctt > 0) ans++;
    cout << ans << "\n";
  }

  return 0;
}
