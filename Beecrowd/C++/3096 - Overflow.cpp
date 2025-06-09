#include <bits/stdc++.h>
using namespace std;

// simple Stirling formula
int calc(int n){
  return trunc(log10(2*M_PI*n)/2.0 + n*log10(n/exp(1))) + 1;
}

int main(){

  int num; cin >> num;
  cout << calc(num) << endl;

    return 0;
}

