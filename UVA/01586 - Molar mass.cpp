#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  unordered_map<char, double> umap;
  umap['C'] = 12.01;
  umap['H'] = 1.008;
  umap['O'] = 16.00;
  umap['N'] = 14.01;;

  int t; cin >> t;
  while(t--){

    string molecule; cin >> molecule;
    double ans = 0.0;
    for(int i=0; i<molecule.size(); i++){

      char element = molecule[i];
      string mult = "";

      while(i+1 < molecule.size() && isdigit(molecule[i+1]))
        mult += molecule[++i];

      if(mult.empty()) mult = "1";
      int useThis = stoi(mult, nullptr, 10);
      ans += useThis * umap[element];
    }

    cout << fixed << setprecision(3);
    cout << ans << "\n";
  }

  return 0;
}
