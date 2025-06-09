#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string str; getline(cin, str);
    stack<char> st;
    bool hasSolution = true;

    for(auto c : str){
      if(c == '(' || c == '[') st.push(c);
      else if(c == ')' || c == ']'){
        if(st.empty() || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[')){
          hasSolution = false;
          break;
        }
        else st.pop();
      }
    }

    if(hasSolution && st.empty()) cout << "Yes\n";
    else                          cout << "No\n";
  }

  return 0;
}
