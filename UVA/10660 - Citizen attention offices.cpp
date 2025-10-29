#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> tup;

void get_coordinates(int id, int &r, int &c){
  r = id / 5;
  c = id % 5;
}

int manhattan_dist(int r1, int c1, int r2, int c2){
  return abs(r1 - r2) + abs(c1 - c2);
}

int get_cost(int offices[5], const vector<tup> &areas){

  int total_cost = 0;
  for(auto [r, c, w] : areas){
    int min_dist = INT_MAX;
    for(int i=0; i<5; i++){
      int office_r, office_c;
      get_coordinates(offices[i], office_r, office_c);
      int d = manhattan_dist(r, c, office_r, office_c);
      min_dist = min(min_dist, d);
    }
    total_cost += w * min_dist;
  }
  return total_cost;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<tup> areas;
    for(int i=0; i<n; i++){
      int r, c, population; cin >> r >> c >> population;
      areas.emplace_back(r, c, population);
    }

    int cur_off[5], best_offices[5];
    int best_total_cost = INT_MAX;
    for(cur_off[0] = 0; cur_off[0] <= 20; cur_off[0]++){
      for(cur_off[1] = cur_off[0]+1; cur_off[1] <= 21; cur_off[1]++){
        for(cur_off[2] = cur_off[1]+1; cur_off[2] <= 22; cur_off[2]++){
          for(cur_off[3] = cur_off[2]+1; cur_off[3] <= 23; cur_off[3]++){
            for(cur_off[4] = cur_off[3]+1; cur_off[4] <= 24; cur_off[4]++){

              int cur_cost = get_cost(cur_off, areas);
              if(cur_cost < best_total_cost){
                best_total_cost = cur_cost;
                for(int i=0; i<5; i++)
                  best_offices[i] = cur_off[i];
              }
            }
          }
        }
      }
    }

    for(int i=0; i<5; i++){
      if(i > 0) cout << " ";
      cout << best_offices[i];
    }

    cout << endl;
  }

  return 0;
}
