#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
#define MAX 1000001

int main(){

  speedBoost;
  vector<int> table(MAX, 0);
  table[0] = 1;

  ll factorial = 1;
  for(int i=1; i<MAX; i++){
    factorial *= i;
    while(factorial % 10 == 0)
      factorial /= 10;
    table[i] = factorial % 10;
    factorial %= 1000000;
  }

  int n;
  while((cin >> n), n){

    cout << table[n] << "\n";
  }

  return 0;
}
