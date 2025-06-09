#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;

int main(){

  speedBoost;
  string line;
  while(cin >> line){

    if(line == "#") break;

    unordered_map<char, unordered_set<char>> graph;
    unordered_set<char> sequence;
    stringstream ss(line);

    string data;
    while(getline(ss, data, ';')){
      char u = data[0]; // A:BC gets A
      sequence.insert(u);
      string neighbors = data.substr(data.find(':')+1);
      for(auto c : neighbors){
        sequence.insert(c);
        graph[u].insert(c);
      }
    }

    int ans = INF;
    string permuteThis = "", bestSeq = "";

    for(auto c : sequence) permuteThis += c;
    sort(permuteThis.begin(), permuteThis.end());

    do{
        vector<int> distances(26);
        for(int i=0; i<permuteThis.size(); i++) distances[permuteThis[i] - 'A'] = i;
        int maxBand = 1;
        for(int i=0; i<permuteThis.size(); i++){
          char u = permuteThis[i];
          for(auto v : graph[u])
            maxBand = max(abs(distances[v - 'A'] - i), maxBand);
        }

        if(maxBand < ans){
          ans = maxBand;
          bestSeq = permuteThis;
        }

    } while(next_permutation(permuteThis.begin(), permuteThis.end()));

    for(auto c : bestSeq) cout << c << " ";
    cout << "-> " << ans << "\n";
  }

  return 0;
}
