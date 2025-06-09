#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){             // simple problem of
  if(num < 2) return false;        // sieve of eratosthenes
  for(int x=2; x*x <=num; x++)     // without variants or special cases
    if(num%x == 0) return false;
  return true;
}


int main() {

  int n; cin >> n;
  while(n--){
    int number; cin >> number;
    if(isPrime(number)) cout << "Prime" << endl;
    else                cout << "Not Prime" << endl;
  }
    return 0;
}
