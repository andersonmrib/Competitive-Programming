#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

vi vis, match;

enum {VISITED = -1, UNVISITED = -2};

bool can_match(const vi &ja, const vi &ji){
  for(int i=0; i<26; i++)
    if(ja[i] < ji[i]) return false;

  return true;
}

int Aug(int L){
  if(vis[L] == VISITED) return 0;
  vis[L] = VISITED;
  for(auto R : AL[L])
    if((match[R] == -1) || Aug(match[R])){
      match[R] = L;
      return 1;
    }
  return 0;
}

int main(){

  speedBoost;
  int V, C;
  while(cin >> V >> C){

    vector<string> jack(V), jill(C);
    for(int i=0; i<V; i++)
      cin >> jack[i];
    for(int i=0; i<C; i++)
      cin >> jill[i];

    vector<vi> jack_freq(V, vi(26, 0));
    for(int i=0; i<V; i++)
      for(auto c : jack[i])
        jack_freq[i][c - 'a']++;

    vector<vi> jill_freq(C, vi(26, 0));
    for(int i=0; i<C; i++)
      for(auto c : jill[i])
        jill_freq[i][c - 'a']++;

    AL.assign(V, vi());
    for(int i=0; i<V; i++)
      for(int j=0; j<C; j++)
        if(can_match(jack_freq[i], jill_freq[j]))
          AL[i].push_back(j);

    match.assign(C, -1);
    int max_matches = 0;
    for(int i=0; i<V; i++){
      vis.assign(V, UNVISITED);
      max_matches += Aug(i);
    }

    cout << max_matches << endl;
  }

  return 0;
}
