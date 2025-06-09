#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> ii;

int main(){

  speedBoost;
  priority_queue<ii, vector<ii>, greater<ii>> minHeap;
  unordered_map<int, int> mapper;

  string reg; int id, period;
  while(cin >> reg){
    if(reg == "#") break;
    cin >> id >> period;
    mapper[id] = period;
    minHeap.push({period, id});
  }

  int k; cin >> k;
  while(k--){
    ii ans = minHeap.top(); minHeap.pop();
    cout << ans.second << endl;
    ans.first += mapper[ans.second];
    minHeap.push(ans);
  }

  return 0;
}
