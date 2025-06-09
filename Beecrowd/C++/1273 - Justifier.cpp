#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  bool first = true;
  while((cin >> n), n){

    if(!first) cout << "\n";
    first = false;

    int longest = 0;
    vector<string> names;
    for(int i=0; i<n; i++){
      string str; cin >> str;
      names.push_back(str);
      if(str.size() > longest) longest = str.size();
    }

    for(auto &s : names) cout << setw(longest) << right << s << "\n";
  }

  return 0;
}

