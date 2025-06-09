#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  int fib[51];
  fib[0] = 0;
  fib[1] = 1, fib[2] = 2;
  for(int i=3; i<51; i++)
    fib[i] = fib[i-1] + fib[i-2];

  int n;
  while((cin >> n), n)
    cout << fib[n] << "\n";

  return 0;
}
