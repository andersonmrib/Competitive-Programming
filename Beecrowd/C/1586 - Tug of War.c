#include <stdio.h>
#include <string.h>
typedef long long ll;

int main(){

  int n;
  int points[100010];
  char names[100010][15];

  while(scanf("%d", &n), n){
    getchar();
    ll B_noWeigth = 0;
    ll B = 0;          // team B
    for(int i=1; i<=n; i++){
      points[i] = 0;
      scanf("%s", names[i]);
      for(int j=0; j<strlen(names[i]); j++)
        points[i] += names[i][j];
      B_noWeigth += points[i];
      B += points[i] * i;
    }

    int ans = 0;
    ll A = 0;          // team A
    ll A_noWeigth = 0;
    for(int i=1; i<=n; i++){
      B -= B_noWeigth;
      B_noWeigth -= points[i];
      A_noWeigth += points[i];
      A += A_noWeigth;
      if(A == B){
        ans = i;
        break;
      }
      if(A > B) break;
    }

    if(!ans) printf("Impossibilidade de empate.\n");
    else     printf("%s\n", names[ans]);
  }

  return 0;
}
