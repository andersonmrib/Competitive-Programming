#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  while((cin >> n), n){

    stack<char> st;
    queue<char> q;
    vector<char> vec;
    string ans;

    for(int i=0; i<n; i++){
      char c; cin >> c;
      vec.push_back(c);
    }

    for(int i=0; i<n; i++){
      char c; cin >> c;
      q.push(c);
    }

    bool possible = true;
    int i=0;
    while(i<n || !st.empty()){

      if(i<n){
        st.push(vec[i]);
        ans += 'I';
        i++;
      }

      while(!st.empty() && st.top() == q.front()){
        st.pop(), q.pop();
        ans += 'R';
      }

      if(!st.empty() && st.top() != q.front()){
        if(i == n){
          possible = false;
          break;
        }
      }
    }

    if(possible && q.empty()) cout << ans << endl;
    else                      cout << ans << " Impossible" << endl;
  }

  return 0;
}
