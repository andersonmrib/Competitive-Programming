#include <bits/stdc++.h>
using namespace std;

int main(){

  unordered_map<string, string> umap;

  int n; cin >> n;
  cin.ignore();
  for(int i=0; i<n; i++){
    string language, translation;
    getline(cin, language);
    getline(cin, translation);
    umap[language] = translation;
  }

  int m; cin >> m;
  cin.ignore();
  vector<string> names;
  for(int i=0; i<m; i++){
    string name, language;
    getline(cin, name);
    getline(cin, language);
    cout << name << "\n" << umap[language] << "\n" << "\n";
  }

    return 0;
}
