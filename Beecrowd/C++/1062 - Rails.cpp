#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, x;
  stack<int> A, B, S; // S for station

  while(cin >> n, n){
    while(cin >> x){
      if(!x){
        cout << endl;
        break;
      }

      while(!A.empty()) A.pop();
      while(!B.empty()) B.pop();
      while(!S.empty()) S.pop();

      A.push(x), B.push(1);
      for(int i=2; i<=n; i++){
        cin >> x;
        A.push(x), B.push(i);
      }

      while(!A.empty() || !B.empty() || !S.empty()){
        if(!A.empty() && !B.empty() && A.top() == B.top()){
          A.pop(), B.pop();
        }
        else if(!S.empty() && !B.empty() && S.top() == B.top()){
          S.pop(), B.pop();
        }
        else if(!A.empty()){
          S.push(A.top());
          A.pop();
        }
        else break;
      }

      if(A.empty() && B.empty() && S.empty()) cout << "Yes\n";
      else                                    cout << "No\n";
    }
  }
    return 0;
}
