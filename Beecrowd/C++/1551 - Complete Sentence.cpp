#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; cin >> n;
  cin.ignore();
  while(n--){
    string str; getline(cin, str);

    set<char> letters;

    for(auto c : str){
      if(tolower(c) >= 'a' && tolower(c) <= 'z')
        letters.insert(c);
      else continue;
    }

    if(letters.size() == 26)      cout << "frase completa\n";
    else if(letters.size() >= 13) cout << "frase quase completa\n";
    else                          cout << "frase mal elaborada\n";
  }

  return 0;
}
