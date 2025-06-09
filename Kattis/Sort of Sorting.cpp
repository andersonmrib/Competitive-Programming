#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool comp(const string &a, const string &b){
  return a.substr(0, 2) < b.substr(0, 2);
}

int main(){

  int n;
  while((cin >> n), n){

    vector<string> vec;
    for(int i=0; i<n; i++){
      string s; cin >> s;
      vec.push_back(s);
    }

    stable_sort(vec.begin(), vec.end(), comp);

    for(auto s : vec)
      cout << s << endl;

    if(n) cout << endl;
  }

  return 0;
}
