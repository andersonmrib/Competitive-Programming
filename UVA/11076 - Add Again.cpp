#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

int main(){

  speedBoost;

  ull factorial[13];
  factorial[0] = factorial[1] = 1;
  for(int i=2; i<13; i++)
    factorial[i] = factorial[i-1] * i;

  int N;
  while((cin >> N), N){

    vector<int> digits(N);
    vector<int> frequency(10, 0);

    int digitsSum = 0;
    for(int i=0; i<N; i++){
      cin >> digits[i];
      frequency[digits[i]]++;
      digitsSum += digits[i];
    }

    ull permutation = factorial[N];
    for(int i=0; i<10; i++)
      permutation /= factorial[frequency[i]];

    ull temp = 0, power = 1;
    for(int i=0; i<N; i++){
      temp += power;
      power *= 10;
    }
    ull ans = permutation * digitsSum/N * temp;

    cout << ans << "\n";
  }

  return 0;
}
