#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  vector<string> vec;
  set<string> dictionary;

  string str;
  while(cin >> str)
    vec.push_back(str);


  for(int i=0; i<vec.size(); i++){
    for(int j=i+1; j<vec.size(); j++){
      dictionary.insert(vec[i]+vec[j]);
      dictionary.insert(vec[j]+vec[i]);
    }
  }

  for(auto word : dictionary)
    cout << word << "\n";

  return 0;
}
