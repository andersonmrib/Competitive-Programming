#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

const int MAX_N = 1e6+1;

int main(){

  speedBoost;
  vector<int> numDiv(MAX_N);
  for(int i=1; i<MAX_N; i++)
    for(int j=i; j<MAX_N; j+=i)
      numDiv[j]++;

  int n; cin >> n;
  while(n--){
    int x; cin >> x;
    cout << numDiv[x] << endl;
  }

  return 0;
}
