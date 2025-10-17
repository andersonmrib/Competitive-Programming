#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

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
    for(auto v : A){
      if(B.count(v) == 0)
        unique_Alice++;
    }

    int unique_Betty = 0;
    for(auto v : B){
      if(A.count(v) == 0)
        unique_Betty++;
    }

    cout << min(unique_Alice, unique_Betty) << endl;
  }

  return 0;
}
