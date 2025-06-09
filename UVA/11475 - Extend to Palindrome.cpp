#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int prime = 131;

const int N = 1e6+1;
int Pow[N];

void preCompute(){
  Pow[0] = 1;
  for(int i=1; i<N; i++)
    Pow[i] = (Pow[i-1] * prime)%MOD;
}

int32_t main(){

  speedBoost;
  preCompute();
  string str;
  while(cin >> str){
    int n = str.size();
    int h = 0, rh = 0, idx = n-1;
    for(int i=n-1; i>=0; i--){
      h = (h * prime + str[i])%MOD;
      rh = (rh + str[i] * Pow[n-i-1])%MOD;
      if(h == rh) idx = i;
    }

    string rev = str.substr(0, idx);
    reverse(rev.begin(), rev.end());
    cout << str << rev << "\n";
  }

  return 0;
}
