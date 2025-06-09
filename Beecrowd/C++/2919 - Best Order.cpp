#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){
  speedBoost;
  int n;
  while(cin >> n){

    vi A;
    for(int i=0; i<n; i++){
      int num; cin >> num;
      A.push_back(num);
    }

    int k = 0;
    vi L(n, -1);

    for(int i=0; i<n; i++){
      int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
      L[pos] = A[i];
      if(pos == k){
        k = pos+1;
      }
    }
    cout << k << endl;
  }

  return 0;
}
