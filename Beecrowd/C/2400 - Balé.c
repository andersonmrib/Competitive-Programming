#include <stdio.h>
#include <string.h>

#define LSOne(S) ((S) & -(S))
#define MAX 100001
typedef long long ll;

ll ft[MAX];
int n;

ll rsq(int j){
  ll sum = 0;
  for(; j; j -= LSOne(j))
    sum += ft[j];
  return sum;
}

void update(int i, ll v){
  for(; i<=n; i += LSOne(i))
    ft[i] += v;
}

int main(){

  scanf("%d", &n);
  memset(ft, 0, sizeof(ft));

  ll ans = 0;
  for(int i=1; i<=n; i++){
    int x; scanf("%d", &x);
    ans += (i-1) - rsq(x - 1);
    update(x, 1);
  }
  printf("%lld\n", ans);


  return 0;
}
