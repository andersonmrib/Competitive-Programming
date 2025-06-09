#include <stdio.h>

int main() {
  int k;
  while (scanf("%d", &k), k) {
    int n, m;
    scanf("%d %d", &n, &m);

    while (k--) {
      int x, y;
      scanf("%d %d", &x, &y);
      x -= n, y -= m;

      if (y > 0) {
        if      (x > 0) printf("NE\n");
        else if (x < 0) printf("NO\n");
        else            printf("divisa\n");
      } else if (y < 0) {
        if      (x > 0) printf("SE\n");
        else if (x < 0) printf("SO\n");
        else            printf("divisa\n");
      } else            printf("divisa\n");

    }
  }
  return 0;
}
