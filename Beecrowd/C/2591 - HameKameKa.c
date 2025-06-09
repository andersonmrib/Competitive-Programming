#include <stdio.h>
#include <string.h>

int main() {
  int  c;
  scanf("%d", &c);
  getchar();

  while (c--){
    char  str[210];
    scanf("%s", str);

    int  firstPart = 0, secondPart = 0;
    int  f = 1, s = 0;

    for (int  i = 0; i < strlen(str); i++){
      if (f && str[i] == 'a'){
        firstPart++;
      } else if (str[i] == 'k'){
        f = 0;
        s = 1;
      } else if (s && str[i] == 'a'){
        secondPart++;
      }
    }

    int  quantity = firstPart * secondPart;

    printf("k");
    for (int  i = 0; i < quantity; i++){
      printf("a");
    }
    printf("\n");
  }

  return 0;
}
