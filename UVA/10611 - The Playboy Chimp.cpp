#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  vector<int> heights(n);

  for(int i=0; i<n; i++)
    cin >> heights[i];

  int q; cin >> q;
  while(q--){

    int h; cin >> h;
    int low = lower_bound(heights.begin(), heights.end(), h) - heights.begin();
    if(low == 0)
      cout << "X ";
    else
      cout << heights[low-1] << " ";

    int high = upper_bound(heights.begin(), heights.end(), h) - heights.begin();
    if(high == n)
      cout << "X\n";
    else
      cout << heights[high] << endl;
  }

  return 0;
}
