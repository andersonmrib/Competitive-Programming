#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
              tree_order_statistics_node_update> ost;

const int N = 2000005;
int lucky[N], dp[N];

// Thanks to Hikari9 - https://github.com/Hikari9/UVa/blob/master/10909%20-%20Lucky%20Number.cpp
// Was struggling to scape TLE

int main(){

  ost tree;
  for(int i=1; i<N; i+=2)
    tree.insert(i);

  for(auto it : tree){
    if(it == 1) continue;
    int current = it;

    if(current > tree.size()) break;
    for(int j=current-1; j<tree.size(); j+=current-1)
      tree.erase(tree.find_by_order(j));
  }

  for(auto it : tree)
    lucky[it] = 1;

  int n;
  while(scanf("%d", &n) != EOF){

    if(n&1) printf("%d is not the sum of two luckies!\n", n);
    else{
      if(!dp[n]){                  // Not computed before
        dp[n] = -1;                // n cannot be the sum of the 2 number, e.g: 1 cannot be the sum of 2 numbers, just like 3, and 7...
        for(int i=n/2; i>=1; i--){ // Smart mathematic approach, pay attention to the relation of the indexes ans values
          if(lucky[i] && lucky[n-i]){
            dp[n] = i;             // stores the index
            break;
          }
        }
      }
      if(dp[n] == -1) printf("%d is not the sum of two luckies!\n");
      else            printf("%d is the sum of %d and %d.\n", n, dp[n], n-dp[n]);
    }
  }

  return 0;
}
