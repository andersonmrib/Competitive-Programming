#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n;
  while((cin >> n), n){

    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    for(int i=0; i<n; i++){
      int x; cin >> x;
      pq.push(x);
    }

    int ans = 0;
    while(pq.size() > 1){
      int first = pq.top(); pq.pop();
      int second = pq.top(); pq.pop();

      int cost = first + second;
      ans += cost;

      pq.push(cost);
    }
    cout << ans << "\n";
  }

  return 0;
}
