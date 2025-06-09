#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

string toBinary(int decimal){
  string str = "";
  if(decimal == 0){
    str = "0";
    return str;
  }

  while(decimal){
    int mod = decimal%2;
    if(mod == 0) str += '0';
    else         str += '1';

    decimal /= 2;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(){
  speedBoost;
  int n;
  while((cin >> n), n){
    string binaryString = toBinary(n);
    int ans = 0;

    for(auto x : binaryString)
      if(x == '1') ans++;

    printf("The parity of %s is %d (mod 2).\n", binaryString.c_str(), ans);
  }

  return 0;
}
