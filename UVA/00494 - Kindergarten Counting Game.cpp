#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool isWord(const string &str){
  if(str.empty()) return false;
  for(char c : str)
    if(!isalpha(c)) return false;
  return true;
}

int main(){

  speedBoost;

  string str;
  while(getline(cin, str)){

    for(auto &c : str)
      if(!isalpha(c)) c = ' ';

    stringstream ss(str);
    string data;
    int ans = 0;

    while(ss >> data)
      if(isWord(data)) ans++;

    cout << ans << "\n";
  }

  return 0;
}
