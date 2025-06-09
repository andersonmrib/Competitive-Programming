#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int precedence(char Operator){
  switch(Operator){
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
  }
}

int main(){

  stack<char> st4ck; //This code uses the Shunting Yard algorithm. 
  int n; cin >> n;

  while(n--){
    string expression;
    cin >> expression;

    while(!st4ck.empty()) st4ck.pop();

    for(int i=0; i<expression.length(); i++){
        if(isalpha(expression[i]) || isdigit(expression[i]))
            cout << expression[i];
        else if(expression[i] == '(')
            st4ck.push(expression[i]);
        else if(expression[i] == ')'){
            while(!st4ck.empty() && st4ck.top() != '('){
                cout << st4ck.top();
                st4ck.pop();
            }
            if(!st4ck.empty()) st4ck.pop(); //removes '(' after completing while loop
        }
        else{
           while(!st4ck.empty() && st4ck.top() != '(' && precedence(expression[i]) <= precedence(st4ck.top())){
                 cout << st4ck.top();
                 st4ck.pop(); //removes everything until it finds a '()
           }
           st4ck.push(expression[i]); //Push the operator
        }
    }

    while(!st4ck.empty()){
        cout << st4ck.top();
        st4ck.pop();
    }
    cout << endl;
  }
}
