#include <bits/stdc++.h>
#include <bits/extc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main(){

  speedBoost;
  int n; cin >> n;
  ost s;
  for(int i=1; i<=n; i++)
    s.insert(i);

   int pos = 0;
   while(!s.empty()){

     int sz = s.size();
     pos = (pos + 1) % sz;

     auto it = s.find_by_order(pos);
     cout << *it << (sz == 1 ? "" : " ");
     s.erase(it);
   }

  return 0;
}
