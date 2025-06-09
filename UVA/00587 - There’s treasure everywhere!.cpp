#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define EPS 1e-9
using namespace std;

struct point{
  double x, y;
  point() {x = 0.0, y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
};

int main(){

  speedBoost;
  unordered_map<string, pair<double, double>> directions = {
    {"N", {0, 1}}, {"NE", {sqrt(2)/2, sqrt(2)/2}}, {"E", {1, 0}},
    {"SE", {sqrt(2)/2, -sqrt(2)/2}}, {"S", {0, -1}}, {"SW", {-sqrt(2)/2, -sqrt(2)/2}},
    {"W", {-1, 0}}, {"NW", {-sqrt(2)/2, sqrt(2)/2}}
  };

  string line;
  int NC = 0;
  while(getline(cin, line)){

    if(line == "END") break;

    line.pop_back();
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    point p(0, 0);
    size_t pos = 0;

    while(pos < line.size()){

      size_t numEnd = pos;

      while(numEnd < line.size() && isdigit(line[numEnd])) numEnd++;
      if(numEnd == pos) break;

      int units = stoi(line.substr(pos, numEnd - pos));
      pos = numEnd;

      size_t dirEnd = pos;
      while(dirEnd < line.size() && isalpha(line[dirEnd])) dirEnd++;

      string dir = line.substr(pos, dirEnd - pos);
      pos = dirEnd + 1; // Comma skip

      p.x += units * directions[dir].first;
      p.y += units * directions[dir].second;
    }

    double dist = sqrt(p.x * p.x + p.y * p.y);

    cout << fixed << setprecision(3);
    cout << "Map #" << ++NC << "\n";
    cout << "The treasure is located at (" << p.x << "," << p.y << ").\n";
    cout << "The distance to the treasure is " << dist << ".\n\n";
  }

  return 0;
}
