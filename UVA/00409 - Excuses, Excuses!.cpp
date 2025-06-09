#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int K, E;
  int NC = 0;
  while(cin >> K >> E){

    unordered_map<string, int> umap;
    for(int i=0; i<K; i++){
      string w; cin >> w;
      umap[w] = 1;
    }

    vector<pair<int, string>> excuses;
    int higherExc = -1;
    for(int i=0; i<E; i++){
      string line; getline(cin, line);
      string cpy = line;
      for(auto &c : cpy) if(!isalpha(c)) c = ' ';
      transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
      stringstream ss(cpy);
      string word;
      int freq = 0;
      while(ss >> word){
        if(umap[word]) freq++;
      }
      excuses.push_back({freq, line});
      if(freq > higherExc) higherExc = freq;
    }
    string dummy; getline(cin, dummy);

    cout << "Excuse Set #" << ++NC << "\n";
    for(auto [f, str] : excuses)
      if(f == higherExc) cout << str << "\n";
    cout << "\n";
  }

  return 0;
}
