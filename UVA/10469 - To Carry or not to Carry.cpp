#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  unsigned int a, b;
  while(cin >> a >> b){
    int t = a^b;
    cout << t << endl;
  }

  return 0;
}
