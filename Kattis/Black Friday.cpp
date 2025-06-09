#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; cin >> n;
  vector<int> vec;
  unordered_map<int, int> mapper;
  unordered_map<int, int> index;

  for(int i=0; i<n; i++){
    int a; cin >> a;
    mapper[a]++;
    index[a] = i+1;
    vec.push_back(a);
  }

  sort(vec.rbegin(), vec.rend());

  bool solution = false;
  for(auto x : vec){
    if(mapper[x] == 1){
      cout << index[x] << endl;
      solution = true;
      break;
    }
  }

  if(!solution) cout << "none" << endl;

  return 0;
}
