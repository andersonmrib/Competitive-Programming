#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

  char str[20]; scanf("%s", str);
  str[0] = tolower(str[0]);

  if(str[0] == 'o' || str[0] == 'c') printf("mas\n");  // use "contrariedade" for "mas"
  else                               printf("mais\n");

    return 0;
}

