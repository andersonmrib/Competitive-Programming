#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct soldier{
  int briefing, job;
  bool operator <(const soldier &other) const{
    return other.job < job;
  }
};

int main(){

  speedBoost;
  int n;
  int NC = 0;
  while((cin >> n), n){

    vector<soldier> squad(n);
    for(int i=0; i<n; i++)
      cin >> squad[i].briefing >> squad[i].job;

    sort(squad.begin(), squad.end());

    int curTime = 0, totalTime = 0;
    for(auto s : squad){
      curTime += s.briefing;
      totalTime = max(totalTime, curTime + s.job);
    }

    cout << "Case " << ++NC << ": " << totalTime << "\n";
  }

  return 0;
}
