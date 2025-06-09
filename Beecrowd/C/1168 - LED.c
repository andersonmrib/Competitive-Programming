#include <stdio.h>

int main() {

  int n, numberOfLeds;
  char value[101];
  int LEDs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  scanf("%d", &n);

  for (int i=0;i<n;i++)
  {
    scanf("%s", &value);

    numberOfLeds = 0;

    for(int j=0;j<strlen(value);j++)
      numberOfLeds += LEDs[value[j] - '0'];

        printf("%d leds\n", numberOfLeds);
  }

  return 0;
}
