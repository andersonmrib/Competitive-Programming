#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  string m;

  while(cin >> n >> m){
    int sum = 0;
    for(auto c : m) sum += c - '0';

    cout << sum;
    if(sum % 3 == 0) cout << " sim\n";
    else             cout << " nao\n";
  }

  return 0;
}
