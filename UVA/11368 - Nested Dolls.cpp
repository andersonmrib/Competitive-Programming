#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

bool comp(const ii &a, const ii &b){
  if(a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int m; cin >> m;
    vector<ii> dolls;
    for(int i=0; i<m; i++){
      int w, h; cin >> w >> h;
      dolls.push_back({w, h});
    }

    sort(dolls.begin(), dolls.end(), comp);

    deque<int> deq;
    for(int i=0; i<m; i++){
      int pos = lower_bound(deq.begin(), deq.end(), dolls[i].second) - deq.begin();
      if(pos == 0) deq.push_front(dolls[i].second);
      else         deq[pos-1] = dolls[i].second;
    }
    cout << deq.size() << "\n";
  }

  return 0;
}
