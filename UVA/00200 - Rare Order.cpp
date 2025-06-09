#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

enum {UNVISITED = -1, VISITED = -2};
vector<vector<int>> AL;
vector<int> dfs_num;
vector<int> result;

void toposort(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
        toposort(v);
    result.push_back(u);
}

int main(){

  string str;
  vector<string> vec;
  set<char> s;

  while(getline(cin, str)){
    if (str == "#") break;
    vec.push_back(str);
  }

  AL.assign(26, vector<int>());
  dfs_num.assign(26, UNVISITED);
  result.clear();

  for(int i=0; i<vec.size(); i++){
    for(auto c : vec[i])
        s.insert(c);
  }

  for(int i=0; i<vec.size(); i++){
    for(int j=i+1; j<vec.size(); j++){
        int id = 0; // used to compare letter by letter
        while(id < vec[i].size() && id < vec[j].size()){
            if(vec[i][id] != vec[j][id]){
                AL[vec[i][id] - 'A'].emplace_back(vec[j][id] - 'A');
                break;
            }
            id++;
        }
    }
  }

  for(auto c : s){
     if(dfs_num[c - 'A'] == UNVISITED)
       toposort(c - 'A');
  }

  reverse(result.begin(), result.end());

  for(int i=0; i<result.size(); i++)
    cout << char(result[i] + 'A');
  cout << endl;

  return 0;
}
