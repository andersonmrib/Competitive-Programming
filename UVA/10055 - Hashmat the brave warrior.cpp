#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  ll hashmat, enemy;
  while(cin >> hashmat >> enemy)
    cout << abs(hashmat - enemy) << endl;

  return 0;
}
