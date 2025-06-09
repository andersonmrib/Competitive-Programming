#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str;
  while(getline(cin, str)){

    int pos=0, i;
    stack<char> st;

    for(i=0; i<str.size(); i++){
      pos++;
      char c = str[i], d = str[i+1];
      if(c == '[' || c == '{' || c == '<'){
        st.push(c);
        continue;
      }
      if(c == '('){
        if(d == '*'){
          i++;
          st.push('*');
         }
         else st.push(c);
         continue;
      }

      if(c == ')' || c == ']' || c == '}' || c == '>' || (c == '*' && d == ')')){
        if(st.empty()) break;
        if(c == ')' && st.top() != '(') break;
        else if(c == ']' && st.top() != '[') break;
        else if(c == '}' && st.top() != '{') break;
        else if(c == '>' && st.top() != '<') break;
        else if(c == '*' && st.top() != '*') break;
        else if(c == ')' || c == ']' || c == '}' || c == '>' || (c == '*' && d == ')'))
          st.pop();
        if(c == '*' && d == ')') i++;
      }
    }

    if(!st.empty() || i < str.size()){
      if(i == str.size() && !st.empty()) pos++;
      cout << "NO " << pos << "\n";
    }
    else cout << "YES\n";
  }

  return 0;
}
