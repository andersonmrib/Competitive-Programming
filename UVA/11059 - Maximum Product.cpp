#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N;
  int NC = 0;
  while(cin >> N){

    vector<int> vec(N);
    for(int i=0; i<N; i++)
      cin >> vec[i];

    long long ans = 0;
    for(int i=0; i<N; i++){
      long long prod = 1;
      for(int j=i; j<N; j++){
        prod *= vec[j];
        ans = max(ans, prod);
      }
    }

    cout << "Case #" << ++NC << ": The maximum product is " << ans << ".\n\n";
  }


  return 0;
}
