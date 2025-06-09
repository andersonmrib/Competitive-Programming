#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  unordered_map<int, int> freq;
  vector<int> vec;
  vector<int> order;

  int number;
  while(cin >> number){
    vec.push_back(number);
    if(!freq[number]) order.push_back(number);
    freq[number]++;
  }

  for(auto x : order)
    cout << x << " " << freq[x] << "\n";


  return 0;
}
