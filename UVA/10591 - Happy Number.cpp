#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

ll check(int n){

  ll sum = 0;
  while(n){
    sum += ((n % 10) * (n % 10));
    n /= 10;
  }
  return sum;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    int number; cin >> number;
    int tmp = number;
    while(true){
      tmp = check(tmp);
      if(tmp / 10 == 0) break;
    }

    if(tmp == 1)
      cout << "Case #" << ++numCases << ": "<< number <<" is a Happy number.\n";
    else
      cout << "Case #" << ++numCases << ": " << number << " is an Unhappy number.\n";
  }

  return 0;
}
