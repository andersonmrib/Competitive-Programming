#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N;
  while((cin >> N), N){

    int ans = 0;
    for(int i=1; i<=N; i++)
      ans += i*i;
    cout << ans << "\n";
  }

  return 0;
}
