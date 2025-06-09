#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int arr[] = {40320, 5040, 720, 120, 24, 6, 2, 1};

  int N; cin >> N;
  int ans = 0;
  for(int i=0; i<8; i++){

    ans += N/arr[i];
    N %= arr[i];
  }

  cout << ans << "\n";

  return 0;
}
