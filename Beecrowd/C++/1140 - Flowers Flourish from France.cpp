#include <bits/stdc++.h>
using namespace std;

int main(){

  string str;
  while(getline(cin, str)){
    if(str[0] == '*') break;

    stringstream ss(str);
    string word;

    bool tautogram = true;
    ss >> word;
    char examine = tolower(word[0]);

    while(ss >> word){
      if(tolower(word[0]) != examine){
        tautogram = false;
        break;
      }
    }
    cout << (tautogram ? "Y\n" : "N\n");
  }

  return 0;
}
