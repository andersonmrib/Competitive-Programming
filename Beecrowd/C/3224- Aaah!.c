#include <stdio.h>
#include <string.h>

int main(){

  char strMarius[1010], strDoctor[1010];
  scanf("%s %s", strMarius, strDoctor);
  if(strlen(strDoctor) > strlen(strMarius))
    printf("no\n");
  else printf("go\n");

  return 0;
}
