#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, cost;
  while(cin >> n >> cost){

    if(!n){ cout << 0 << endl; continue; }

    vector<int> vec;
    for(int i=0; i<n; i++){
      int revenue; cin >> revenue;
      vec.push_back(revenue - cost);
    }

    int ans = 0, sum = 0;
    for(int i=0; i<n; i++){
      sum += vec[i];
      ans = max(ans, sum);
      if(sum < 0) sum = 0;
    }

    cout << ans << endl;
  }

  return 0;
}
