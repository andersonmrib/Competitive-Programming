#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

const int MAX_VALUE = 1e6;

int main(){

  speedBoost;
  int n; cin >> n;
  vector<int> vec(n), freq(MAX_VALUE+1, 0);
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    freq[x]++;
  }

  for(int gcd=MAX_VALUE; gcd>0; gcd--){
    int numDiv = 0;
    for(int j=gcd; j<=MAX_VALUE; j+= gcd)
      numDiv += freq[j];
    if(numDiv >= 2){
      cout << gcd << endl;
      break;
    }
  }


  return 0;
}
