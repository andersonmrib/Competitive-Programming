#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int precedence(char op){
  switch(op){
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    default: return 0;
  }
}

int main(){

  speedBoost;

  int t; cin >> t; cin.ignore();
  string dummy; getline(cin, dummy);
  bool first = true;

  while(t--){

    if(!first) cout << "\n";
    first = false;

    string line;
    string expression = "";
    while(getline(cin, line)){
      if(line == "") break;
      else expression += line;
    }

    stack<char> st;
    for(char c : expression){
      if(isalpha(c) || isdigit(c)) cout << c;
      else if(c == '(') st.push(c);
      else if(c == ')'){
        while(!st.empty() && st.top() != '('){
          cout << st.top();
          st.pop();
        }
        if(!st.empty()) st.pop(); // removes remaining '('
      }
      else{
        while(!st.empty() && st.top() != '(' && precedence(c) <= precedence(st.top())){
          cout << st.top();
          st.pop();
        }
        st.push(c);
      }
    }

    while(!st.empty()){
      cout << st.top();
      st.pop();
    }
    cout << "\n";
  }

  return 0;
}
