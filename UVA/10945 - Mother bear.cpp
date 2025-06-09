#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  while(getline(cin, line)){

    if(line == "DONE") break;
    string cleaned;
    for(auto &c : line){
      if(isalpha(c))
        cleaned += tolower(c);
    }

    string rev = cleaned;
    reverse(rev.begin(), rev.end());

    if(cleaned == rev)
      cout << "You won't be eaten!\n";
    else
      cout << "Uh oh..\n";
  }


  return 0;
}
