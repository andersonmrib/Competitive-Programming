#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  unordered_map<char, char> umap;
  umap['@'] = 'a';
  umap['&'] = 'e';
  umap['!'] = 'i';
  umap['*'] = 'o';
  umap['#'] = 'u';

  string str;
  while(getline(cin, str)){

    for(auto c : str){
      if(c == '@' || c == '&' || c == '!' ||
         c == '*' || c == '#')
         c = umap[c];
      cout << c;
    }
    cout << "\n";
  }

  return 0;
}
