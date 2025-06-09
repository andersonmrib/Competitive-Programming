#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  unordered_map<int, int> umap = {
  {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
  {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
  };

  int d1, m1, d2, m2;
  cin >> d1 >> m1 >> d2 >> m2;

  int total = 0;
  if(m1 == m2)
    total = d2 - d1;
  else{
    total += umap[m1] - d1;
    for(int i=m1+1; i<m2; i++)
      total += umap[i];
    total += d2;
  }

  cout << total << "\n";

  return 0;
}
