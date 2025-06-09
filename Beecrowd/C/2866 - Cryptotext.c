#include <stdio.h>
#include <string.h>

int main (){

  int n; scanf ("%d", &n);

  while(n--){

    char str[100]; scanf ("%s", str);
    for (int i=strlen(str); i> -1; i--)
        if (str[i] > 90) printf ("%c", str[i]);
        printf ("\n");
  }

  return 0;
}
