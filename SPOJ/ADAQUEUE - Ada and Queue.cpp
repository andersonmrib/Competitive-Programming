#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

using namespace std;

void solve() {

  int n; cin >> n;
  deque<int> d;
  bool rev = false;
  while(n--){

    string cmd; cin >> cmd;
    if(cmd == "back"){
      if(d.empty()){
        cout << "No job for Ada?" << endl;
        continue;
      }
      if(rev == false){
        cout << d.back() << endl;
        d.erase(d.end());
        continue;
      }
      cout << d.front() << endl;
      d.erase(d.begin());
    }

    else if(cmd == "front"){
      if(d.empty()){
        cout << "No job for Ada?" << endl;
        continue;
      }
      if(rev == false){
        cout << d.front() << endl;
        d.erase(d.begin());
        continue;
      }
      cout << d.back() << endl;
      d.erase(d.end());
    }

    else if(cmd == "reverse")
      rev = !rev;

    else if(cmd == "push_back"){
      int x; cin >> x;
      if(rev == false) d.push_back(x);
      else             d.push_front(x);
    }

    else if(cmd == "toFront"){
      int x; cin >> x;
      if(rev == false) d.push_front(x);
      else             d.push_back(x);
    }
  }
}

int32_t main(){

  speedBoost;
    solve();

  return 0;
}
