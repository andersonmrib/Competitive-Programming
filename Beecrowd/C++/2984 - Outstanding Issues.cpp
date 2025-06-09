#include <bits/stdc++.h>
using namespace std;

int main(){

  string str; cin >> str;

  stack<char> st;

  for(auto c : str){
    if(c == '(') st.push(c);
    else{
      if(!st.empty() && st.top() == '('){
        st.pop();
      }
    }
  }

  if(st.empty()) cout << "Partiu RU!\n";
  else           cout << "Ainda temos " << st.size() << " assunto(s) pendente(s)!\n";

  return 0;
}
