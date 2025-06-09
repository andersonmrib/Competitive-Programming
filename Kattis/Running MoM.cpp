#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi degree;

int main() {

  int n;
  cin >> n;

  AL.assign(n, vi());
  degree.assign(n, 0);
  unordered_map<string, int> umap;

  int coun = 0;
  for(int i=0; i<n; i++){
    string city1, city2;
    cin >> city1 >> city2;

    if(umap.count(city1) == 0){
      umap[city1] = coun;
      coun++;
    }
    if(umap.count(city2) == 0){
      umap[city2] = coun;
      coun++;
    }

    int n1 = umap[city1];
    int n2 = umap[city2];

    AL[n2].emplace_back(n1);             // going to make a reverse AL
    degree[n1]++;                        // you can fly from city 1 to another...
  }

  queue<int> checker;
  for(int i=0; i<coun; i++)              // gets every city that does not have a fly to another one (1)
    if(degree[i] == 0) checker.push(i);

  vector<bool> safeCities(coun, true);
  while(!checker.empty()){
    int curr = checker.front();
    checker.pop();

    safeCities[curr] = false;           // same city as (1), mark as false (not safe)
    for(auto v : AL[curr]){             // visits every adjacency vertex
      degree[v]--;                      // reduce the degree, as this city it is not safe
      if(degree[v] == 0)
        checker.push(v);                // repeat the process
    }
  }

  string city;
  while(cin >> city){
    int vertex = umap[city];
    cout << city;
    if(safeCities[vertex]) cout << " safe" << endl;
    else                   cout << " trapped" << endl;
  }

  return 0;
}
