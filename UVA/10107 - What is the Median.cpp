#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
  speedBoost;
  vector<int> vec;
  int value, mid1, mid2;
  while(cin >> value){

    vec.push_back(value);
    sort(vec.begin(), vec.end());

    mid1 = vec.size()/2 -1, mid2 = vec.size()/2;

    if(vec.size() == 1) cout << vec[0] << "\n";
    else
      if(vec.size() % 2 == 0)
        cout << (vec[mid1] + vec[mid2])/2 << "\n";
      else
        cout << vec[mid2] << "\n";
  }

  return 0;
}
