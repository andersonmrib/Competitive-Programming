#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, number;
  vector<int> even, odd;

  cin >> n;

  for(int i = 0; i<n; i++){
    cin >> number;
    if(number%2 == 0) even.push_back(number);
    else              odd.push_back(number);
  }

  sort(even.begin(), even.end());
  sort(odd.rbegin(), odd.rend());

  for(int x:even) cout << x << endl;
  for(int x:odd)  cout << x << endl;

  return 0;
}
