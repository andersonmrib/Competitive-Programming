#include <stdio.h>

int main(){

  char c;
  long long ans = 0;
  while(scanf("%c", &c) != EOF){
    if(c == '0' || c == '1')
      ans <<= 1;
    if(c == '1')
      ans += 1;
    ans %= 131071;
    if(c == '#'){
      ans == 0 ? printf("YES\n") : printf("NO\n");
      ans = 0;
    }
  }

  return 0;
}
