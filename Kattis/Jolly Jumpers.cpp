#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while(cin >> n){
    vector<int> arr(n);
    vector<int> ans(n-1);

    for(int i=0; i<n; i++)
      cin >> arr[i];

    for(int i=1; i<n; i++){
      int getAbs = abs(arr[i] - arr[i-1]);
      ans[i-1] = getAbs;
    }

    bool isJolly = true;
    sort(ans.begin(), ans.end());

    for(int i=1; i<ans.size(); i++)
      if(ans[i] - ans[i-1] != 1){
      isJolly = false;
      break;
    }

    if(isJolly) cout << "Jolly\n";
    else cout << "Not jolly\n";
  }

  return 0;
}
