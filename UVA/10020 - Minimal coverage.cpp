#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> ii;

int main(){

  speedBoost;
  int TC; cin >> TC;
  while(TC--){
    int M; string dummy; bool first = true;
    cin >> M;

    // cin.ignore(); getline(cin, dummy);

    vector<ii> vec;
    int l, r;
    while((cin >> l >> r), (l||r)){
      vec.push_back({l, r});
    }

    // if(TC != 1) getline(cin, dummy);
    sort(vec.begin(), vec.end());

    vector<int> bestCoordinates;
    bool possible = true;
    int covered = 0, ans = 0;
    for(int i=0; (i < vec.size()) && possible; i++){ // starts checking i-th segment
      if(covered >= M) break;                        // done
      if(vec[i].second < covered) continue;          // cannot help us
      if(vec[i].first <= covered){                   // found a candidate
        int maxRange = -1e9;                         // going to use maxRange to store the furthest point wee can get
        int max_id;                                  // ... and this guy for the id of the furthest point
        for(int j=i; (j < vec.size()) && (vec[j].first <= covered); j++) // starts checking everyone on the right until it stops
          if(vec[j].second > maxRange){             // we can increase the range here
            maxRange = vec[j].second;               // just update variables
            max_id = j;
          }
          bestCoordinates.push_back(max_id);         // and put the id of the optimal segment here
          ans++;
          covered = maxRange;
      }
      else possible = false;
    }

    if(!possible || covered < M) cout << 0 << endl;
    else{
      cout << ans << endl;
      for(int i=0; i<bestCoordinates.size(); i++)
        cout << vec[bestCoordinates[i]].first << " " << vec[bestCoordinates[i]].second << endl;
    }

    if(TC) cout << endl;
  }

  return 0;
}

/*
// Alternative code, same running time

#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct st{
  int l, r;
  bool operator<(const st &other) const{
    return l < other.l;
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int m; cin >> m;
    vector<st> vec;
    vector<st> coordinates;

    int x, y;
    while((cin >> x >> y), (x || y))
      vec.push_back({x, y});

    sort(vec.begin(), vec.end());

    int ans, covered, i;
    ans = covered = i = 0;

    bool possible = true;
    while(covered < m){
      int max_r = -1;
      int j;
      st best;

      for(j=i; j<vec.size() && vec[j].l <= covered; j++)
        if(vec[j].r > max_r){
          max_r = vec[j].r;
          best = vec[j];
        }

      if(max_r <= covered){
        possible = false;
        break;
      }

      coordinates.push_back(best);
      covered = max_r;
      i=j;
    }

    if(!possible) cout << 0 << "\n";
    else{
      cout << coordinates.size() << "\n";
      for(auto c : coordinates)
        cout << c.l << " " << c.r << "\n";
    }

    if(t) cout << "\n";
  }

  return 0;
}

*/
