#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int b, s;
  int NC = 0;
  while((cin >> b >> s), (b || s)){

    vector<int> bachelor(b), spinster(s);
    for(int i=0; i<b; i++) cin >> bachelor[i];
    for(int i=0; i<s; i++) cin >> spinster[i];

    cout << "Case " << ++NC << ": ";
    if(b > s){
      sort(bachelor.begin(), bachelor.end());
      cout << b - s << " " << bachelor[0] << "\n";
    }
    else
      cout << 0 << "\n";
  }

  return 0;
}
