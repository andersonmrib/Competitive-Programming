#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n;
  string treeName;
  bool first = true;

  cin >> n;
  cin.ignore();
  getline(cin, treeName); // just captures an empty tree name
  while(n--){
    int total = 0;
    map<string, float> trees;

    while(getline(cin, treeName) && !treeName.empty()){
        trees[treeName]++;
        total++;
    }

    if(first) first = false;
    else      cout << endl;

    for(auto it=trees.begin(); it != trees.end(); it++){
      cout << it->first << " "; printf("%.4f\n", 100.0 * (it->second/total));
    }
  }

  return 0;
}
