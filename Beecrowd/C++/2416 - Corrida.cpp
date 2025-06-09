#include <bits/stdc++.h>
using namespace std;

int main(){

  int c, n; cin >> c >> n;
  cout << (c+n)%n << endl;  // moves to the right and flips to zero:
                            // 0 - 1 - 2 - 3 ... - 0 - 1...
  return 0;
}
