#include <bits/stdc++.h>
using namespace std;

int main(){

  string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  unordered_map<char, char> umap;
  string str;

  while(getline(cin, str)){
  for(int i=1; i<keyboard.size(); i++)
    umap[keyboard[i]] = keyboard[i-1];

  for(auto c : str){
    if(c == ' ') cout << " ";
    else cout << umap[c];
  }
  cout << endl;
  }

  return 0;
}
