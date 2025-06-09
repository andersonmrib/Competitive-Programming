#include <bits/stdc++.h>
using namespace std;

int main(){

  string expression;
  stack<char> st;
  int length;
  while(cin >> expression){
    int parenthesis = 0;

    length = 0;
    for(auto c : expression){
      if(c == '(') parenthesis++;
      else if(c == ')'){
        if(parenthesis > 0) parenthesis--;
        else break;
      }
      length++;
    }

    if(!parenthesis && length == expression.size()) cout << "correct\n";
    else                                            cout << "incorrect\n";
  }

  return 0;
}
