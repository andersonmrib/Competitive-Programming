#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;
             // There will be duplicates, so just use 'less_equal'
             // but be aware that erasing functions may not work

int main(){

  int t; scanf("%d", &t);
  while(t--){

    ost tree;

    ll sum = 0;
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++){
      int num; scanf("%d", &num);
      tree.insert(num);

      // check if it's odd
      if(i&1) sum += *tree.find_by_order(i/2);
      else    sum += (*tree.find_by_order(i/2) + *tree.find_by_order(i/2-1))/2;
    }
    printf("%lld\n", sum);
  }

  return 0;
}
