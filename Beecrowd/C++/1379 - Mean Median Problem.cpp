#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  ll a, b;
  while((cin >> a >> b), (a||b)){
    cout << 2*a - b << endl;
  }

  return 0;
}

/*

  Imagine that C <= A <= B or
               A <= C <= B or
               A <= B <=  C
  We can have three types of medians, and consequently,
  3 types of means.

  mean = median
  A = (A+B+C)/3 -> 3A = 3(A+B+C)/3 = 2A - B or
  C = ...                          = (A+B)/2
  B = ....                         = 3B - A

*/
