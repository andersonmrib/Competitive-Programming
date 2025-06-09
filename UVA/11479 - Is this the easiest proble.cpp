#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    ll tri[3];
    for(int i=0; i<3; i++)
      cin >> tri[i];

    sort(tri, tri+3);
    ll a = tri[0], b = tri[1], c = tri[2];

    if((a + b > c) == false){
      cout << "Case " << ++numCases << ": Invalid\n";
      continue;
    }
    else{
      if(a == b && b == c){
        cout << "Case " << ++numCases << ": Equilateral\n";
        continue;
      }
      else if((a == b) || (b == c)){
        cout << "Case " << ++numCases << ": Isosceles\n";
        continue;
      }
      else{
        cout << "Case " << ++numCases << ": Scalene\n";
        continue;
      }
    }
  }

  return 0;
}
