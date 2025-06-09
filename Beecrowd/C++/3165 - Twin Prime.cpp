#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool isPrime(int n){
  if(n < 2) return false;
  for(int x=2; x*x <= n; x++)
    if(n%x == 0) return false;
  return true;
}

int main(){

  //speedBoost;
  int N; cin >> N;
  vector<int> vec;

  for(int i=N; i>=2; i--){
    if(isPrime(i)){
      if(isPrime(i-2)){
        vec.push_back(i), vec.push_back(i-2);
        break;
      }
    }
  }

  cout << vec[1] << " " << vec[0] << endl;

  return 0;
}
