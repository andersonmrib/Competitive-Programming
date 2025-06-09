#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int main (){

  bool first = true;
  int n;
  while(scanf("%d", &n), n){
    if(!first) printf("\n");

    first = false;
    bool hasSolution = false;
    for(int fghij = 1234; fghij <= 98765/n; fghij++){ // use of fghij/n for keeting the range of 5 numbers
        int abcde = fghij*n;
        int tmp, mask = (fghij < 10000); // bitmask will tell us all the occurrences of every digit. Remember fghij begins with 0!
        tmp = abcde; while(tmp) { mask |= 1<<(tmp%10); tmp /= 10; }
        tmp = fghij; while(tmp) { mask |= 1<<(tmp%10); tmp /= 10; }
        if(mask == (1<<10)-1){ // if all the digits are being used
            printf("%05d / %05d = %d\n", abcde, fghij, n);
            hasSolution = true;
        }
    }
    if(!hasSolution) printf("There are no solutions for %d.\n", n);
  }
  return 0;
}
