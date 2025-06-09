#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  string keyboard = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,.";
  unordered_map<char, char> change;

  for(int i=0; i<keyboard.size(); i++)
    change[keyboard[i]] = keyboard[i-2];

  string input; getline(cin, input);
  transform(input.begin(), input.end(), input.begin(), ::tolower);
  for(int i=0; i<input.size(); i++){
    if(input[i] == ' ') cout << " ";
    else                cout << change[input[i]];
  }
  cout << "\n";

  return 0;
}
