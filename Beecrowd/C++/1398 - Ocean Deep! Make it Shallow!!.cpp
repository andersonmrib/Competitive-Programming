#include <bits/stdc++.h>
using namespace std;

int main(){

  char c;
  long long ans = 0;
  while(cin >> c){
    if(c == '0' || c == '1')
      ans <<= 1;
    if(c == '1')
      ans += 1;
    if(c == '#'){
      cout <<  (ans == 0 ? "YES" : "NO") << endl;
      ans = 0;
    }
  }

  return 0;
}
