#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// "One property is the Pisano Period where
// the last one/last two/last three/last four
// digit(s) of a Fibonacci number repeats with
// a period of 60/300/1500/15000, respectively."

int period[] = {60, 300, 1500, 15000};
int digits[] = {10, 100, 1000, 10000};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int a, b, n, m;
    cin >> a >> b >> n >> m;

    m--;
    n %= period[m];

    vector<int> fib;
    fib.push_back(a % digits[m]), fib.push_back(b % digits[m]);

    for(int i=2; i<=n; i++)
      fib.push_back((fib[i-1] + fib[i-2]) % digits[m]);
    cout << fib[n] << "\n";
  }

  return 0;
}
