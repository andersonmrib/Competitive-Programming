#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int a, b;
  while(cin >> a >> b){

    cout << a << " " << b << " ";
    if(a > b) swap(a, b);
    int ans = 0;
    for(int i=a; i<=b; i++){
      int start = i;
      int getCycle = 0;
      for(int j=start; j!=1;){
        if(j&1) j = j*3 + 1;
        else    j = j/2;
        getCycle++;
      }
      getCycle++;
      ans = max(ans, getCycle);
    }
    cout << ans << "\n";
  }

  return 0;
}
