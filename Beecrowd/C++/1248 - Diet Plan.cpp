#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n; cin.ignore();
  while(n--){

    string diet, breakfast, lunch;

    getline(cin, diet);
    getline(cin, breakfast);
    getline(cin, lunch);

    multiset<char> dietSet(diet.begin(), diet.end());

    string consumed = breakfast + lunch;

    bool cheater = false;
    for(auto food : consumed){
      if(dietSet.find(food) == dietSet.end()){
        cheater = true;
        break;
      }
      else
        dietSet.erase(dietSet.find(food));
    }

    if(cheater){
      cout << "CHEATER\n";
      continue;
    }
    else{
      for(auto remaining : dietSet)
        cout << remaining;
    }
    cout << "\n";
  }

  return 0;
}
