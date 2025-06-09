#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;

int main(){

  int t; scanf("%d", &t); getchar();
  char line[25];

  while(t--){
    scanf("%s", line);
    ull n = 0, k = 0;

    for(int i=0; line[i] >= '0' && line[i] <= '9'; i++)
      n = n * 10 + (line[i] - '0');

    for(int i=0; i<strlen(line); i++)
      if(line[i] == '!') k++;

    ull ans = 1;
    int current = n;
    while(current > 0){
      ans *= current;
      current -= k;
    }

    printf("%llu\n", ans);
  }

  return 0;
}
