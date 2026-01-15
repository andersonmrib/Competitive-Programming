#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){

  speedBoost;
  int n; cin >> n;
  vi a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];

  stack<ii> st;
  for(int i=0; i<n; i++){

    bool found = false;
    while(!st.empty()){
      ii top = st.top();
      if(top.first < a[i]){
        cout << top.second << " ";
        found = true;
        break;
      }
      else st.pop();
    }

    if(found == false) cout << "0 ";

    st.push({a[i], i +1});
  }

  return 0;
}
