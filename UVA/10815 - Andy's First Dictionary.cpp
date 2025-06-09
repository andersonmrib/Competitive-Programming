#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  set<string> dictionary;

  string line, word, text;

  while(getline(cin, line)){
    for(char c : line){
        if(isalpha(c))
           text += tolower(c);
        else
            text += ' ';
    }
    text += ' '; // makes sure different lines will be separated by space
  }

  stringstream ss(text);
  while(ss >> word){
    dictionary.insert(word);
  }

  for(auto s : dictionary)
    cout << s << endl;

  return 0;
}
