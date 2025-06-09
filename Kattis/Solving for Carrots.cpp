#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, p; cin >> n >> p;
  cin.ignore();

  string line;
  for(int i=0; i<n; i++)
    getline(cin, line);

  cout << p << "\n";

  return 0;
}
