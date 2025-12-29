#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){

  speedBoost;
  int n; cin >> n;

  vector<ii> events;
  F(i, 0, n){
    int a, b; cin >> a >> b;
    events.emplace_back(a, 1);
    events.emplace_back(b, -1);
  }

  sort(events.begin(), events.end());
  int ans = 0, cur = 0;
  F(i, 0, events.size()){
    cur += events[i].second;
    ans = max(ans, cur);
  }

  cout << ans << endl;

  return 0;
}

