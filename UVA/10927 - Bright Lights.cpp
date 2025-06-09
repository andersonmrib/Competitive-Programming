#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define EPS 1e-9
using namespace std;

struct point{
  double x, y, z, angle, dist;
  point() { x = y = z = angle = dist = 0.0; }
  point(double _x, double _y, double _z)
  : x(_x), y(_y), z(_z), angle(atan2(y,x)), dist(sqrt(x*x + y*y)) {}

  bool operator <(point &other) const{
    if(angle != other.angle)
      return angle < other.angle;
    return dist < other.dist;
  }
};

int main(){

  speedBoost;

  int n;
  int NC = 0;
  while((cin >> n), n){

    vector<point> vec;
    for(int i=0; i<n; i++){
      double x, y, z; cin >> x >> y >> z;
      vec.emplace_back(x, y, z);
    }

    sort(vec.begin(), vec.end());
    // Map angle to height
    unordered_map<double, int> maxH;
    vector<pair<int, int>> hidden;

    for(auto p : vec){

      if(maxH.count(p.angle) && maxH[p.angle] >= p.z)
        hidden.emplace_back(p.x, p.y);
      else
        maxH[p.angle] = p.z;
    }

    sort(hidden.begin(), hidden.end());

    cout << "Data set " << ++NC << ":\n";
    if(hidden.empty())
      cout << "All the lights are visible.\n";
    else{
      cout << "Some lights are not visible:\n";
      for(int i=0; i<hidden.size(); i++){
        cout << "x = " << hidden[i].first << ", y = " << hidden[i].second;
        if(i+1 < hidden.size()) cout << ";";
        else                    cout << ".";
        cout << "\n";
      }
    }
  }

  return 0;
}
