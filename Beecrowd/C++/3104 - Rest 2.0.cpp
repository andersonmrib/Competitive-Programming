#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){

  speedBoost;
  string a;
  int b;
  long long module = 0;

  cin >> a >> b;

  for(auto c : a)                          // good technique for manipulating big numbers
    module = (module * 10 + (c - '0'))%b;  // (checks if it is divisible or not, module operations, etc)

  cout << module << endl;

  return 0;
}
