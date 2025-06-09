#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
#define MAX 100000

int main(){

  speedBoost;

  int table[MAX+1] = {0};
  table[0] = 1;

  ll factorial = 1;
  for(int i=1; i<MAX+1; i++){
    factorial *= i;
    while(factorial % 10 == 0) // Keeps removing trailing zeros
      factorial /= 10;
    table[i] = factorial % 10; // Stores the last non zero digit
    factorial %= MAX;          // We only need to work with the last digits
  }                            // for precision


  int n;
  while(cin >> n){
    cout << setw(5) << n << " -> " << table[n] << "\n";
  }

  return 0;
}
