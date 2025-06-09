#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

unordered_map<char, vector<char>> graph;
unordered_map<char, int> in_degree;
unordered_set<char> visited;
vector<char> letters;
vector<char> order;

void backtrack(){
  bool found = false;
  for(auto v : letters){
    if(!visited.count(v) && in_degree[v] == 0){
      visited.insert(v);
      order.push_back(v);

      for(auto neighbor : graph[v])
        in_degree[neighbor]--;

      backtrack();

      for(auto neighbor : graph[v])
        in_degree[neighbor]++;

      visited.erase(v);
      order.pop_back();
      found = true;
    }
  }
  if(!found){
    for(auto c : order)
      cout << c;
    cout << "\n";
  }
}

int main(){

  string line, constraint;
  bool first = true;
  while(getline(cin, line)){

    if(!first) cout << "\n";
    first = false;

    graph.clear();
    in_degree.clear();
    letters.clear();
    order.clear();
    visited.clear();

    stringstream ss(line);
    char v;
    while(ss >> v){
      letters.push_back(v);
      in_degree[v] = 0;
    }
    sort(letters.begin(),  letters.end());

    getline(cin, constraint);
    stringstream cs(constraint);
    char a, b;
    while(cs >> a >> b){
      graph[a].push_back(b);
      in_degree[b]++;
    }

    backtrack();
  }

  return 0;
}
