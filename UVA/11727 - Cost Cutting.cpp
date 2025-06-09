#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int t; cin >> t;
  int numCase = 0;
  while(t--){

    vector<int> vec(3, 0);
    for(int i=0; i<3; i++)
      cin >> vec[i];

    sort(vec.begin(), vec.end());

    cout << "Case " << ++numCase << ": " << vec[1] << endl;
  }

  return 0;
}
