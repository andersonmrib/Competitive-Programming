#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

struct player{
  string name;
  int attack;
  int defense;
};

bool compare(const player &p1, const player &p2){
  return p1.name < p2.name;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 1;
  while(t--){

    vector<player> vec(10);
    for(int i=0; i<10; i++)
      cin >> vec[i].name >> vec[i].attack >> vec[i].defense;

    sort(vec.begin(), vec.end(), compare);

    vector<int> permutation(10); // 1 for attack, and 0 for defense
    fill(permutation.begin(), permutation.begin() + 5, 1);
    fill(permutation.begin() + 5, permutation.end(), 0);

    int best_attack_sum = -1;
    int best_defense_sum = -1;
    vector<string> best_attack_players;
    vector<string> best_defense_players;

    do{

      int cur_attack_sum = 0;
      int cur_defense_sum = 0;
      vector<string> cur_attack_players;
      vector<string> cur_defense_players;

      for(int i=0; i<10; i++){
        if(permutation[i] == 1){
          cur_attack_sum += vec[i].attack;
          cur_attack_players.push_back(vec[i].name);
        }
        else{
          cur_defense_sum += vec[i].defense;
          cur_defense_players.push_back(vec[i].name);
        }
      }

      if(cur_attack_sum > best_attack_sum){
        best_attack_sum = cur_attack_sum;
        best_defense_sum = cur_defense_sum;
        best_attack_players = cur_attack_players;
        best_defense_players = cur_defense_players;
      }
      else if(cur_attack_sum == best_attack_sum && cur_defense_sum > best_defense_sum){
        best_defense_sum = cur_defense_sum;
        best_attack_players = cur_attack_players;
        best_defense_players = cur_defense_players;
      }

    } while(prev_permutation(permutation.begin(), permutation.end()));

    cout << "Case " << NC++ << ":\n";
    cout << "(";
    for(int i=0; i<5; i++){
      if(i < 4)
        cout << best_attack_players[i] << ", ";
      else if(i == 4)
        cout << best_attack_players[i] << ")\n";
    }

    cout << "(";
    for(int i=0; i<5; i++){
      if(i < 4)
        cout << best_defense_players[i] << ", ";
      else if(i == 4)
        cout << best_defense_players[i] << ")\n";
    }
  }

  return 0;
}
