#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, s; cin >> n >> s;

  int lower = 10000;
  for(int i=0; i<n; i++){
    int value; cin >> value;
    s += value;
    if(s < lower) lower = s;
  }

  cout << lower << endl;

  return 0;
}
