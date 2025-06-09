#include <stdio.h>
#include <string.h>

int main(){

  int n; scanf("%d", &n);
  getchar();

  while(n--){
    char str[110];
    fgets(str, 110, stdin);
    int len = strlen(str);

    if (str[len-1] =='\n') {
        str[len-1] = '\0';
    len = strlen(str);
    }

    for(int i=(len/2)-1; i>=0; i--)
        printf("%c", str[i]);

    for (int i=len-1; i>=len/2; i--)
        printf("%c", str[i]);

        printf("\n");
  }

  return 0;
}
