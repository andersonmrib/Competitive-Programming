#include <stdio.h>
#include <math.h>

long int rafael(int x, int y);
long int beto(int x, int y);
long int carlos(int x, int y);

int main(){

  int n;
  scanf("%d", &n);
  int x, y;
  while (n--){
    scanf("%d %d", &x, &y);
    long int r = rafael(x,y), b = beto(x,y), c = carlos(x,y);
    if (r > b && r > c) printf ("Rafael ganhou\n");
    else if(b > r && b > c) printf ("Beto ganhou\n");
    else if(c > r && c > b) printf ("Carlos ganhou\n");
  }

  return 0;
}

long int rafael(int x, int y){
  return (pow(3*x,2) + pow(y,2));
}

long int beto(int x, int y){
  return (2*pow(x,2) + pow(5*y,2));
}

long int carlos(int x, int y){
  return -100*x + pow(y,3);
}
