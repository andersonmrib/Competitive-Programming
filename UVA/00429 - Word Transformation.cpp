#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

bool differByOne(string a, string b){
  if(a.size() != b.size()) return false;

  bool aux = false;
  for(int i=0; i<a.size(); i++){
    if(a[i] != b[i]){
      if(aux) return false;
      else    aux = true;
    }
  }
  if(aux) return true;
  return false;
}

int bfs(vector<vi> &graph, int source, vector<string> vec, string b){

  if(vec[source] == b) return 0;

  queue<int> q; q.push(source);
  vector<bool> visited(graph.size(), false);
  visited[source] = true;
  int counter = 0;

  while(!q.empty()){
    counter++;

    int qSize = q.size();
    while(qSize--){

      int u = q.front(); q.pop();
      if(vec[u] == b) return counter - 1;

      for(auto v : graph[u]){
        if(!visited[v]){
          visited[v] = true;
          q.push(v);
        }
      }
    }
  }
  return -1;
}

int main(){

  speedBoost;
  int N; cin >> N;
  while(N--){

    AL.assign(202, vi());
    vector<string> vec;
    unordered_map<string, int> mapper;

    string word;
    int counter = 0;
    while((cin >> word) && word != "*"){
      vec.push_back(word);
      if(!mapper[word])
        mapper[word] = counter++;

      for(int i=0; i<vec.size(); i++){
        if(differByOne(vec[i], word)){
          AL[i].emplace_back(mapper[word]);
          AL[mapper[word]].emplace_back(i);
        }
      }
    }

    string a, b, input;
    cin.ignore();

    while(getline(cin, input) && !input.empty()){
      stringstream ss(input);
      ss >> a >> b;
      int ans = bfs(AL, mapper[a], vec, b);
      cout << a << " " << b << " " << ans << "\n";
    }
    if(N) cout << "\n";
  }

  return 0;
}
