#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  unordered_map<string, string> umap;
  umap["HELLO"] = "ENGLISH";
  umap["HOLA"] = "SPANISH";
  umap["HALLO"] = "GERMAN";
  umap["BONJOUR"] = "FRENCH";
  umap["CIAO"] = "ITALIAN";
  umap["ZDRAVSTVUJTE"] = "RUSSIAN";

  string data;
  int NC = 0;
  while(cin >> data){

    if(data == "#") break;

    cout << "Case " << ++NC << ": ";
    if(umap.find(data) != umap.end())
      cout << umap[data] << "\n";
    else
      cout << "UNKNOWN\n";
  }

  return 0;
}
