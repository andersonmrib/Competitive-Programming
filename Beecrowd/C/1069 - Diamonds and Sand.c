#include <stdio.h>
#include <string.h>

int main(){

  int n; scanf("%d", &n);
  char expression[1001];
  int diamondPiece, fullDiamond;

  while(n--){
    scanf("%s", expression);
    int len = strlen(expression);

    diamondPiece = 0; //Going to fill this every '<' found (half diamond)
    fullDiamond = 0; //Number of diamond we want

    for (int i=0;i<len;i++){
        if(expression[i] == '<') diamondPiece++;
        else if(expression[i] == '>' && diamondPiece > 0) //Found the piece remaining
        {
            fullDiamond++; //Gets a new full diamond and...
            diamondPiece--; //... decrements the half we had
        }
    }
    printf("%d\n", fullDiamond);
  }

  return 0;
}
