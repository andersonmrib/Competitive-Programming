#include <stdio.h>

int main(){

  int n, i; scanf ("%d", &n);
  int star[n], sheep[n];
  long long int sumTraks = 0, sumSheep = 0;

  for (i=0;i<n;i++){
    scanf ("%d", &sheep[i]);
    star[i] = 0;
  }

  i=0;
  while(1)
  {
      if (i == 0 && sheep[i]%2 == 0) //Case for finishing the game
      {
          star[i] = 1;
          if(sheep[i] > 0) sheep[i]--;
          break;
      }
      else if (i == n-1 && sheep[i]%2 == 1) //Another case that cause the game to finish.
      {
          star[i] = 1;
          sheep[i]--;
          break;
      }
      else if (sheep[i]%2 == 1) //Number of sheep in i is Odd.
      {
          sheep[i]--;
          star[i] = 1;
          i++; //Goes ahead and keeps stealing.
      }
      else if (sheep[i]%2 == 0) //Number of sheep in i is Even.
      {
          star[i] = 1;
          if (sheep[i] > 0) sheep[i]--;
          i--; //Turn back and keeps stealing.
      }
  }

  for (i=0;i<n;i++){
    sumTraks += star[i];
    sumSheep += sheep[i];
  }

  printf ("%lld %lld\n", sumTraks, sumSheep);

  return 0;
}
