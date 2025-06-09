#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    string str = to_string(n);
    while(true){
      if(str.size() == 1) break;
      int sum = 0;
      for(auto c : str)
        sum += c - '0';
      str = to_string(sum);
    }
    cout << str << "\n";
  }

  return 0;
}
