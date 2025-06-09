#include <stdio.h>

int main (){

  int ih, im, fh, fm; //Initial hour, initial minute, final hour, final minute.

  scanf ("%d %d %d %d", &ih, &im, &fh, &fm);

  int dif = ((fh*60) + fm) - ((ih*60) + im);

  if (dif <= 0) dif += 24*60;

  printf ("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dif/60, dif%60);

  return 0;
}
