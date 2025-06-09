#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  bool first = true;
  while(t--){

    if(!first) cout << "\n";
    first = false;

    int hangar_x, hangar_y;
    cin >> hangar_x >> hangar_y;
    getline(cin, dummy);

    string line;
    double total_dist = 0.0;
    int x1, y1, x2, y2;

    while(getline(cin, line)){
      if(line.empty()) break;
      stringstream ss(line);
      ss >> x1 >> y1 >> x2 >> y2;
      double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
      total_dist += dist/1000.0;
    }

    total_dist *= 2;
    double totalTime = total_dist/20.0;

    int hours = totalTime;
    int minutes = round((totalTime - hours) * 60);

    if(minutes == 60){
      hours++;
      minutes = 0;
    }

    if(minutes < 10) cout << hours << ":0" << minutes << "\n";
    else             cout << hours << ":" << minutes << "\n";
  }

  return 0;
}
