#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str;
  while(getline(cin, str)){

    bool up = false, low = false, digit = false, punctuation = true, len = true;
    for(auto c : str){
      if(str.size() < 6 || str.size() > 32){
        len = false;
        break;
      }
      if(c >= 'a' && c <= 'z')      up = true;
      else if(c >= 'A' && c <= 'Z') low = true;
      else if(c >= '0' && c <= '9') digit = true;
      else{
        punctuation = false;
        break;
      }
    }

    if(up && low && digit && punctuation && len)
      cout << "Senha valida.\n";
    else
      cout << "Senha invalida.\n";
  }

  return 0;
}
