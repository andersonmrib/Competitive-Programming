#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int p, g;
  string name, comp;
  float value;
  unordered_map<string, float> votes;

  cin >> p >> g;
  while(p--){
    cin >> name >> value;
    votes[name] = value*10;
  }

  for(int i=1; i<=g; i++){
    int total = 0;
    cin >> name >> comp;
    total += votes[name];

    while(comp == "+"){
        cin >> name >> comp;
        total += votes[name];
    }

    int judgeThis;
    cin >> judgeThis;
    judgeThis *= 10;
    cout << "Guess #" << i << " was ";
    if     (comp == "=" && total == judgeThis)  cout << "correct."   << endl;
    else if(comp == "<" && total < judgeThis)   cout << "correct."   << endl;
    else if(comp == "<=" && total <= judgeThis) cout << "correct."   << endl;
    else if(comp == ">" && total > judgeThis)   cout << "correct."   << endl;
    else if(comp == ">=" && total >= judgeThis) cout << "correct."   << endl;
    else                                        cout << "incorrect." << endl;
  }

  return 0;
}
