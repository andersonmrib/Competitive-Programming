#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

string normalize(string email){
  int at_pos = email.find('@');
  string local = email.substr(0, at_pos);
  string domain = email.substr(at_pos);

  int plus_pos = local.find('+');
  if(plus_pos != string::npos)
    local = local.substr(0, plus_pos);

  string cleaned;
  for(auto c : local)
    if(c != '.')
      cleaned += c;

  return cleaned + domain;
}

int main(){

  speedBoost;
  int n; cin >> n;

  unordered_set<string> uset;
  string email;
  for(int i=0; i<n; i++){
    cin >> email;
    uset.insert(normalize(email));
  }

  cout << uset.size() << "\n";

  return 0;
}
