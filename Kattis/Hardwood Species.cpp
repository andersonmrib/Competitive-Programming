#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  string treeName;
  int total = 0;
  map<string, float> trees;

  while(getline(cin, treeName) && !treeName.empty()){
      trees[treeName]++;
      total++;
  }

  for(auto it=trees.begin(); it != trees.end(); it++){
    cout << it->first << " "; printf("%.6f\n", 100.0 * (it->second/total));
  }

  return 0;
}
