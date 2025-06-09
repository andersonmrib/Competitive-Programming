#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int tc; cin >> tc;
  while(tc--){

    string str; cin >> str;
    int numOfSetEle; cin >> numOfSetEle;

    vi numbers(numOfSetEle);
    for(int i=0; i<numOfSetEle; i++)
      cin >> numbers[i];

    bool ok = true;
    for(auto x : numbers){

      int mod = 0;
      for(auto y : str)
        mod = (mod * 10 + y - '0') % x;
      if(mod != 0) ok = false;
    }

    if(ok) cout << str << " - Wonderful.\n";
    else   cout << str << " - Simple.\n";
  }

  return 0;
}
