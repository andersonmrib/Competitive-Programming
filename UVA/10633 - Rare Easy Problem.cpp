#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

int main(){

  ull NM;
  while((cin >> NM), NM){

    ull N = NM * 10 / 9;
    if(NM % 9 == 0)
      cout << N-1 << " " << N << "\n";
    else
      cout << N << "\n";
  }

  return 0;
}
