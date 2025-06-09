#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, t, m; cin >> n >> t >> m;

  int lastBlood[12][2];
  // Stores for each problem, time and teamID
  bool solved[101][12] = {false};

  for(int i=0; i<n; i++){
    lastBlood[i][0] = -1;
    lastBlood[i][1] = -1;
  }

  for(int i=0; i<m; i++){
    int time, teamID;
    char problem;
    string verdict;

    cin >> time >> teamID >> problem >> verdict;
    int problemID = problem - 'A';

    if(verdict == "Yes" && !solved[teamID][problemID]){
      solved[teamID][problemID] = true;

      lastBlood[problemID][0] = time;
      lastBlood[problemID][1] = teamID;
    }
  }

  for(int i=0; i<n; i++){
    if(lastBlood[i][0] == -1)
      cout << char('A' + i) << " - -" << "\n";
    else
      cout << char('A' + i) << " " << lastBlood[i][0] <<
      " " << lastBlood[i][1] << "\n";
  }

  return 0;
}
