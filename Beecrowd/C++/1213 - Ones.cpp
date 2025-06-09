#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  while(cin >> n){
    int repunit = 1, length = 1;

    while(repunit % n != 0){
      repunit = (repunit * 10 + 1) % n;
      length++;
    }
    cout << length << endl;
  }

    return 0;
}
