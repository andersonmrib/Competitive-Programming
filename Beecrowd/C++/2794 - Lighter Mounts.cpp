#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

int main(){

  speedBoost;
  int N; cin >> N;
  vector<ii> vii;

  for(int i=0; i<N; i++){
    int d, t; cin >> d >> t;
    vii.push_back({d, t});
  }

  sort(vii.begin(), vii.end());

  int check = vii[0].second;
  bool hasSolution = true;

  // Simply starts checking if the sequence is decreasing or not
  for(int i=1; i<N; i++){
    if(vii[i].second < check){
      check = vii[i].second;
    }
    else hasSolution = false;
  }

  if(hasSolution) cout << "S\n";
  else            cout << "N\n";

  return 0;
}
