#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int n, d, r;
  while((cin >> n >> d >> r), (n || d | r)){

    vector<int> morning(n), evening(n);

    for(int i=0; i<n; i++)
      cin >> morning[i];
    for(int i=0; i<n; i++)
      cin >> evening[i];

    sort(morning.begin(), morning.end());
    sort(evening.rbegin(), evening.rend());

    int ans = 0;
    for(int i=0; i<n; i++){
      int sum = morning[i] + evening[i];
      if(sum > d) ans += sum - d;
    }
    cout << ans * r << "\n";
  }

  return 0;
}
