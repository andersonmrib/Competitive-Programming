#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int round;
  while(cin >> round){

    if(round == -1) break;

    cout << "Round " << round << endl;

    string sol, guess;
    cin >> sol >> guess;

    unordered_set<char> solution_letters(sol.begin(), sol.end());
    unordered_set<char> guessed_letters;

    int wrong = 0;
    int need = solution_letters.size();
    for(auto c : guess){

      if(guessed_letters.count(c))
        continue;
      guessed_letters.insert(c);

      if(solution_letters.count(c))
        need--;
      else
        wrong++;

      if(need == 0 || wrong >= 7)
        break;
    }

    if(need == 0)
      cout << "You win.\n";
    else if(wrong >= 7)
      cout << "You lose.\n";
    else
      cout << "You chickened out.\n";
  }

  return 0;
}
