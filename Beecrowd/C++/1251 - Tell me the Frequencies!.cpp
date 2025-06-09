#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, char>& a, const pair<int, char>& b){
  if(a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int main(){

  string str;
  bool first = true;
  while(getline(cin, str)){

    if(!first) cout << endl;
    first = false;

    map<char, int> mapper;
    for(auto c : str)
      mapper[c]++;

    vector<pair<int, char>> frequency;
    for(const auto& entry : mapper)
      frequency.emplace_back(entry.second, entry.first);

    sort(frequency.begin(), frequency.end(), comp);

    for(const auto& entry : frequency)
      cout << (int)entry.second << " " << entry.first << endl;
  }

  return 0;
}
