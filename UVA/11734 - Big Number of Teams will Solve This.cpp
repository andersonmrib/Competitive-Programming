#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  int NC = 0;
  while(t--){
    string team, judge;
    getline(cin, team);
    getline(cin, judge);

    cout << "Case " << ++NC << ": ";
    if(team == judge)
      cout << "Yes\n";
    else{
      string noSpaces = team;
      noSpaces.erase(remove(noSpaces.begin(), noSpaces.end(), ' '), noSpaces.end());

      if(noSpaces == judge)
        cout << "Output Format Error\n";
      else
        cout << "Wrong Answer\n";
    }
  }

  return 0;
}
