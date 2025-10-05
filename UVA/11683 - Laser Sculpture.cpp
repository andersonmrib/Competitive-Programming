#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int A, C;
  while(cin >> A >> C, A || C){

    vector<int> vec(C);
    for(int i=0; i<C; i++)
      cin >> vec[i];

    int curr_height = A;
    int ans = 0;
    for(int i=0; i<C; i++){
      if(vec[i] < curr_height)
        ans += curr_height - vec[i];
      curr_height = vec[i];
    }

    cout << ans << "\n";
  }

  return 0;
}
