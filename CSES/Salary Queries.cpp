#include <bits/stdc++.h>
#include <bits/extc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);

#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

const int INF = 1e9;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main(){

  speedBoost;
  int n, q; cin >> n >> q;

  ost s;
  vi salaries(n+1);
  for(int i=1; i<=n; i++){
    cin >> salaries[i];
    s.insert({salaries[i], i});
  }

  while(q--){

    char op; cin >> op;
    if(op == '!'){
      int k, x; cin >> k >> x;
      s.erase({salaries[k], k});
      salaries[k] = x;
      s.insert({x, k});
    }
    else{
      int a, b; cin >> a >> b;
      int below_a = s.order_of_key({a, 1});
      int equal_b = s.order_of_key({b, INF});
      cout << equal_b - below_a << endl;
    }
  }

  return 0;
}

