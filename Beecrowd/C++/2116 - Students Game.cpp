#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
  if(n < 2) return false;
  for(int x=2; x*x <= n; x++)
    if(n%x == 0) return false;
  return true;
}

int main(){

  int N, M; cin >> N >> M;
  int P1, P2;

  for(int i=N; i>=2; i--){
    if(isPrime(i)){
      P1 = i;
      break;
    }
  }

  for(int i=M; i>=2; i--){
    if(isPrime(i)){
      P2 = i;
      break;
    }
  }

  cout << P1*P2 << endl;

  return 0;
}
