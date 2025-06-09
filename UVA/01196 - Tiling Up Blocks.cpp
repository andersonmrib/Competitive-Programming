#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

bool comp(const ii &a, const ii &b){ // {l, m} left and middle
  return ((a.first < b.first) ||
          ((a.first == b.first) && (a.second < b.second)));
  return ((a.first <= b.first) && (a.second <= b.second));
}

int main(){

  int n;
  while((cin >> n), n){

    vii blocks;
    for(int i=0; i<n; i++){
      int l, m; cin >> l >> m;
      blocks.push_back({l, m});
    }

    sort(blocks.begin(), blocks.end(), comp);

    vector<int> L(n, 0);
    int k = 0;
    for(int i=0; i<n; i++){
      int pos = upper_bound(L.begin(), L.begin()+k, blocks[i].second) - L.begin();
      L[pos] = blocks[i].second;
      if(pos == k) k = pos+1;
    }
    cout << k << endl;
  }
  puts("*");

  return 0;
}
