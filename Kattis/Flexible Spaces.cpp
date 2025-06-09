#include <bits/stdc++.h>
using namespace std;

int main(){

  int w, p; cin >> w >> p;

  vector<int> partitions(p);
  for(int i=0; i<p; i++)
    cin >> partitions[i];

  set<int> possibleWidths;

  partitions.insert(partitions.begin(), 0);
  partitions.push_back(w);
  // our partition goes from 0 to w

  for(int i=0; i<= p; i++){
    for(int j=i+1; j<= p+1; j++){
      int width = partitions[j] - partitions[i];
      possibleWidths.insert(width);
    }
  }

  for(int x : possibleWidths)
    cout << x << " ";
  cout << endl;

  return 0;
}

