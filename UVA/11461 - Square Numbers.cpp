#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  vector<int> squareNumbers;
  for(int i=1; i<=318; i++)
    squareNumbers.push_back(i*i);

  int a, b;
  while((cin >> a >> b), (a || b)){

    auto start = lower_bound(squareNumbers.begin(), squareNumbers.end(), a);
    auto end = upper_bound(squareNumbers.begin(), squareNumbers.end(), b);
    cout << distance(start, end) << "\n";
  }

  return 0;
}
