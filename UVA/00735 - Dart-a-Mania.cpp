#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  vector<int> scores;
  scores.push_back(0);      // remember the 2 special values
  scores.push_back(50);

  for(int i=1; i<=20; i++){
    scores.push_back(i);
    scores.push_back(i*2);
    scores.push_back(i*3);
  }

  sort(scores.begin(), scores.end());
  auto it = unique(scores.begin(), scores.end());
  scores.resize(it - scores.begin());

  int n;
  while(scanf("%d", &n), (n > 0)){

    int combination = 0, permutation = 0;

    for(int i=0; i<scores.size(); i++)
      for(int j=i; j<scores.size(); j++)
        for(int k=j; k<scores.size(); k++)
          if(scores[i] + scores[j] + scores[k] == n)
            combination++;

    for(int i=0; i<scores.size(); i++)
      for(int j=0; j<scores.size(); j++)
        for(int k=0; k<scores.size(); k++)
          if(scores[i] + scores[j] + scores[k] == n)
            permutation++;

    if(combination){
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combination);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutation);
    }
    else
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);

    for(int i=0; i<70; i++)
      printf("*");
    printf("\n");
  }
  printf("END OF OUTPUT\n");

  return 0;
}
