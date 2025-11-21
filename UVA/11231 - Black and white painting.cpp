#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int n, m, c;
  while(cin >> n >> m >> c, (n || m || c)){

    int validArea = (n - 7) * (m - 7);
    int ans = (validArea + c) / 2;
    cout << ans << endl;
  }

  return 0;
}
