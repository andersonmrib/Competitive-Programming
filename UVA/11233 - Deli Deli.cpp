#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool isVowel(char c){
  return (c == 'a' || c == 'e' || c == 'i' ||
          c == 'o' || c == 'u');
}

bool case2(string w, int len){
  return (!isVowel(w[len-2]) && w[len-1] == 'y');
}

bool case3(string w, int len){
  return (w[len-1] == 'o' || w[len-1] == 's'  ||
         (w[len-2] == 'c' && w[len-1] == 'h') ||
          (w[len-2] == 's' && w[len-1] == 'h') ||
          w[len-1] == 'x');
}

int main(){

  speedBoost;
  int L, N; cin >> L >> N;

  unordered_map<string, string> umap;
  for(int i=0; i<L; i++){
    string a, b; cin >> a >> b;
    umap[a] = b;
  }

  for(int i=0; i<N; i++){
    string word; cin >> word;
    int len = word.size();

    if(umap.find(word) != umap.end()){
      cout << umap[word] << "\n";
      continue;
    }

    if(case2(word, len)){
      word.erase(len-1);
      word += "ies";
    }
    else if(case3(word, len)){
      word += "es";
    }
    else
      word += "s";

    cout << word << "\n";
  }

  return 0;
}
