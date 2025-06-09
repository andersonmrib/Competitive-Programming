#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  vector<ll> catNum(11, 0);

  catNum[0] = 1;
  for(int i=1; i<11; i++)
    catNum[i] = (catNum[i-1]*(4*(i-1) + 2))/(i+1);

  int n;
  bool first = true;
  while(cin >> n){

    if(!first) cout << "\n";
    first = false;

    cout << catNum[n] << "\n";
  }

  return 0;
}
