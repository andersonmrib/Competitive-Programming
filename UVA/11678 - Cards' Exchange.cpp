#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int a, b;
  while(cin >> a >> b, a || b){

    unordered_set<int> A, B;
    for(int i=0; i<a; i++){
      int x; cin >> x;
      A.insert(x);
    }

    for(int i=0; i<b; i++){
      int x; cin >> x;
      B.insert(x);
    }

    int unique_Alice = 0;
    for(auto card : A){
      if(B.count(card) == 0)
        unique_Alice++;
    }

    int unique_Betty = 0;
    for(auto card : B){
      if(A.count(card) == 0)
        unique_Betty++;
    }

    int ans = min(unique_Alice, unique_Betty);
    cout << ans << endl;
  }

  return 0;
}
