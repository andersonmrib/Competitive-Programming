#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
  speedBoost;
  int n;
  cout << "PERFECTION OUTPUT" << endl;
  while((cin >> n), n){

    int numDivisors = 0;
    for(int i=1; i<=n/2; i++)
      if(n % i == 0) numDivisors += i;

    cout << setw(5) << n << "  ";
    if(numDivisors == n)
      cout << "PERFECT\n";
    else if(numDivisors < n)
      cout << "DEFICIENT\n";
    else
      cout << "ABUNDANT\n";
  }
  cout << "END OF OUTPUT\n";

  return 0;
}
