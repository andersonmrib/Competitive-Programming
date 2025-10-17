#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int e, f, c; cin >> e >> f >> c;
  int total_empty = e + f;

  int sodas = 0;
  while(total_empty >= c){

    int new_sodas = total_empty / c;
    sodas += new_sodas;
    int remaining = total_empty % c;

    total_empty = new_sodas + remaining;
  }

  cout << sodas << endl;

  return 0;
}


