#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;

  while(getline(cin, line)){

    list<char> text;
    auto it = text.begin();

    for(auto c : line){
      if(c == '[') it = text.begin();
      else if(c == ']') it = text.end();
      else text.insert(it, c);
    }

    for(auto c : text)
      cout << c;
    cout << "\n";
  }

  return 0;
}
