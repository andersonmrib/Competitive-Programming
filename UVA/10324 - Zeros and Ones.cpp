#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str;
  int NC = 0;
  while(getline(cin, str)){

    if(str == "") break;

    vector<int> segment(str.size(), 0);
    int cur = 0;
    for(int i=1; i<str.size(); i++){
      if(str[i] != str[i-1]) cur++;
      segment[i] = cur;
    }

    cout << "Case " << ++NC << ":\n";

    int n; cin >> n;
    for(int i=0; i<n; i++){
      int a, b; cin >> a >> b;
      if(segment[a] == segment[b]) cout << "Yes\n";
      else                         cout << "No\n";
    }

    cin.ignore();
  }
  return 0;
}
