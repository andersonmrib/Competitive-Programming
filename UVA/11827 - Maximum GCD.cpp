#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string line;
    getline(cin, line);
    stringstream ss(line);

    int number;
    vector<int> vec;

    while(ss >> number)
      vec.push_back(number);

    int ans = 0;
    for(int i=0; i<vec.size(); i++)
      for(int j=i+1; j<vec.size(); j++)
        ans = max(ans, __gcd(vec[i], vec[j]));

    cout << ans << "\n";
  }

  return 0;
}
