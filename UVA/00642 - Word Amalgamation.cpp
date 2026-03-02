#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  vector<string> dict;
  string word;

  while(cin >> word){
    if(word == "XXXXXX") break;
    dict.push_back(word);
  }

  while(cin >> word){

    if(word == "XXXXXX") break;

    string sorted = word;
    sort(sorted.begin(), sorted.end());

    vector<string> res;
    for(auto s : dict){
      string cmp = s;
      sort(cmp.begin(), cmp.end());
      if(cmp == sorted)
        res.push_back(s);
    }

    if(res.empty())
      cout << "NOT A VALID WORD\n";
    else{
      sort(res.begin(), res.end());
      for(int i=0; i<res.size(); i++)
        cout << res[i] << endl;
    }

    cout << "******\n";
  }

  return 0;
}

