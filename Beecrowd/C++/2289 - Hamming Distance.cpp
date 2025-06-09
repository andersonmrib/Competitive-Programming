#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

 speedBoost;
  unsigned long long x, y;
  while((scanf("%llu %llu", &x, &y)), (x||y)){

    unsigned long long check = x^y;          // applying XOR operation gives us all
    int ans = __builtin_popcountll(check);   // the different bits marked as 1
    printf("%d\n", ans);                     // 1001 XOR 1010 = 0011
  }                                          // you just need to get the number of bits on now

  return 0;
}

// bitwise problems can be tricky...
// try submitting the code below for speed comparison
// and be careful: do not forget to use speedBoost if needed
// (you can remove it to see how narrow the free time limit gets)
/*
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

 speedBoost;
  unsigned long long x, y;
  while((cin >> x >> y), (x||y)){

    unsigned long long check = x^y;          // applying XOR operation gives us all
    int ans = __builtin_popcountll(check);   // the different bits marked as 1
    cout << ans << endl;                     // 1001 XOR 1010 = 0011
  }                                          // you just need to get the number of bits on now

  return 0;
}
*/
