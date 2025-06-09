#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int t; scanf("%d", &t);
  char line[41];
  scanf("%*s%*s%*s%s%*s", line);

  for(int i=0; i<strlen(line); i+=4){
    if(line[i+1] == '*') printf("1");
    else if(line[i] == '*') printf("2");
    else                 printf("3");
  }

  printf("\n");

  return 0;
}
